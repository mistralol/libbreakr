
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct hostent * (*func) (const void *addr, socklen_t len, int type) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct hostent * (*) (const void *addr, socklen_t len, int type)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(addr, len, type);
}



#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct hostent *gethostbyname2(const char *name, int af)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct hostent * (*func) (const char *name, int af) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct hostent * (*) (const char *name, int af)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(name, af);
}


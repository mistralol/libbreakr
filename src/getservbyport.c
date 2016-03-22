
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct servent *getservbyport(int port, const char *proto)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct servent * (*func) (int port, const char *proto) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct servent * (*) (int port, const char *proto)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(port, proto);
}


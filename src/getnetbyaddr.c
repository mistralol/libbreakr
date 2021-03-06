
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct netent *getnetbyaddr(uint32_t net, int type)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct netent * (*func) (uint32_t net, int type) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct netent * (*) (uint32_t net, int type)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(net, type);
}


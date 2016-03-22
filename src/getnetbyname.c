
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct netent *getnetbyname(const char *name)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct netent * (*func) (const char *name) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct netent * (*) (const char *name)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(name);
}


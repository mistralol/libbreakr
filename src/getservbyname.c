
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct servent *getservbyname(const char *name, const char *proto)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct servent * (*func) (const char *name, const char *proto) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct servent * (*) (const char *name, const char *proto)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(name, proto);
}


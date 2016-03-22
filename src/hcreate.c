
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <search.h>

int hcreate(size_t nel)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static int (*func) (size_t nel) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (int (*) (size_t nel)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(nel);
}


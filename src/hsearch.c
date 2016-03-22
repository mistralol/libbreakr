
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <search.h>

ENTRY *hsearch(ENTRY item, ACTION action)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static ENTRY * (*func) (ENTRY item, ACTION action) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (ENTRY * (*) (ENTRY item, ACTION action)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(item, action);
}


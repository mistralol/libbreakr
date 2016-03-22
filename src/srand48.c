
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>

void srand48(long int seedval)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static void (*func) (long int seedval) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (void (*) (long int seedval)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(seedval);
}


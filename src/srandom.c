
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>

void srandom(unsigned int seed)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static void (*func) (unsigned int seed) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (void (*) (unsigned int seed)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(seed);
}


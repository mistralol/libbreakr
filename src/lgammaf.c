
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <math.h>

float lgammaf(float x)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static float (*func) (float x) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (float (*) (float x)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(x);
}


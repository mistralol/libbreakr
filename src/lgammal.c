
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <math.h>

long double lgammal(long double x)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static long double (*func) (long double x) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (long double (*) (long double x)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(x);
}


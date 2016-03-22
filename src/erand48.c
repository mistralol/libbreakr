
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>

double erand48(unsigned short xsubi[3])
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static double (*func)(unsigned short xsubi[3]) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (double (*)(unsigned short xsubi[3])) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(xsubi);
}


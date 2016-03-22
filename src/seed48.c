
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>

unsigned short *seed48(unsigned short seed16v[3])
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static unsigned short * (*func) (unsigned short seed16v[3]) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (unsigned short * (*) (unsigned short seed16v[3])) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(seed16v);
}


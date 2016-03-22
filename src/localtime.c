
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <time.h>

struct tm *localtime(const time_t *timep)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct tm * (*func) (const time_t *timep) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct tm * (*) (const time_t *timep)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(timep);
}


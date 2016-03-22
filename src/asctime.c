#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <time.h>

char *asctime(const struct tm *tm)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static char * (*func) (const struct tm *tm) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (char * (*) (const struct tm *tm)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(tm);
}



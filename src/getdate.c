
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <time.h>

struct tm *getdate(const char *string)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct tm * (*func) (const char *string) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct tm * (*) (const char *string)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(string);
}


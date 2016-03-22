
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <unistd.h>

void setkey(const char *key)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static void (*func) (const char *key) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (void (*) (const char *key)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(key);
}


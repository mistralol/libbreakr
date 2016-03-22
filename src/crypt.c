
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <unistd.h>

char *crypt(const char *key, const char *salt)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static char *(*func) (const char *key, const char *salt) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (char *(*) (const char *key, const char *salt)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(key, salt);
}


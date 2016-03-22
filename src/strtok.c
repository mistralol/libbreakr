
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <string.h>

char *strtok(char *str, const char *delim)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static char * (*func) (char *str, const char *delim) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (char * (*) (char *str, const char *delim)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(str, delim);
}


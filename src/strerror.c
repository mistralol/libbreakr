
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <string.h>

char *strerror(int errnum)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static char * (*func) (int errnum) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (char * (*) (int errnum)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(errnum);
}


#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <unistd.h>

pid_t fork(void)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static pid_t (*func) (void) = NULL;
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (pid_t (*) (void)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	pid_t ret = func();
	if (ret == 0)
	{
		breakr_deactive();
	}
	return ret;
}


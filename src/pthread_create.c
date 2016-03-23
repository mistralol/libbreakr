#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <pthread.h>


int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static int (*func) (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		breakr_activate();
		if (func == NULL)
		{
			func = (int (*) (pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(thread, attr, start_routine, arg);
}


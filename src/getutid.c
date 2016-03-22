
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <utmp.h>

struct utmp *getutid(const struct utmp *ut)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct utmp * (*func) (const struct utmp *ut) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct utmp * (*) (const struct utmp *ut)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(ut);
}


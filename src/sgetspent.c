
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <shadow.h>

struct spwd *sgetspent(const char *s)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct spwd * (*func) (const char *s) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct spwd * (*) (const char *s)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(s);
}


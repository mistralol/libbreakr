
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd *fgetpwent(FILE *stream)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct passwd * (*func) (FILE *stream) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct passwd * (*) (FILE *stream)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(stream);
}


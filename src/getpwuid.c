
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwuid(uid_t uid)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct passwd * (*func) (uid_t uid) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct passwd * (*) (uid_t uid)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(uid);
}


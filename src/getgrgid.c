
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>

struct group *getgrgid(gid_t gid)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct group * (*func) (gid_t gid) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct group * (*) (gid_t gid)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(gid);
}



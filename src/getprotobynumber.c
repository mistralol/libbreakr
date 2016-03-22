
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct protoent *getprotobynumber(int proto)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct protoent * (*func) (int proto) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct protoent * (*) (int proto)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(proto);
}


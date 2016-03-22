
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netdb.h>

struct rpcent *getrpcbynumber(int number)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct rpcent * (*func) (int number) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct rpcent * (*) (int number)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(number);
}


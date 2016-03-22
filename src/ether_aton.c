
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <netinet/ether.h>

struct ether_addr *ether_aton(const char *asc)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static struct ether_addr *(*func) (const char *asc) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (struct ether_addr *(*) (const char *asc)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(asc);
}



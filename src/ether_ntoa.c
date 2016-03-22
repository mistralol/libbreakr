
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>
#include <netinet/ether.h>

char *ether_ntoa(const struct ether_addr *addr)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static char * (*func)(const struct ether_addr *addr) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (char * (*)(const struct ether_addr *addr)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(addr);
}


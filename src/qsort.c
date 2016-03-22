
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static void (*func) (void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (void (*) (void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(base, nmemb, size, compar);
}


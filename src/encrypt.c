
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>

void encrypt(char block[64], int edflag)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static void (*func)(char block[64], int edflag) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (void (*)(char block[64], int edflag)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(block, edflag);
}


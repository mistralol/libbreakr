
#include <config.h>
#include <breakr.h>
#include <pthread.h>
#include <dlfcn.h>

#include <stdlib.h>

char *qfcvt(long double number, int ndigits, int *decpt, int *sign)
{
	static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
	static char * (*func) (long double number, int ndigits, int *decpt, int *sign) = NULL;
	breakr_action(__FUNCTION__);
	
	if (func == NULL)
	{
		LOCK(&lock);
		if (func == NULL)
		{
			func = (char * (*) (long double number, int ndigits, int *decpt, int *sign)) dlsym(RTLD_NEXT, __FUNCTION__);
		}
		UNLOCK(&lock);
	}
	return func(number, ndigits, decpt, sign);
}


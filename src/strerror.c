
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <string.h>

char *strerror(int errnum)
{
	breakr_action(__FUNCTION__);
}


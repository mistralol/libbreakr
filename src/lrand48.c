
#include <config.h>
#include <breakr.h>

#include <stdlib.h>

long int lrand48(void)
{
	breakr_action(__FUNCTION__);
}


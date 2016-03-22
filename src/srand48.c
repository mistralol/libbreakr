
#include <config.h>
#include <breakr.h>

#include <stdlib.h>

void srand48(long int seedval)
{
	breakr_action(__FUNCTION__);
}



#include <config.h>
#include <breakr.h>


#include <stdlib.h>

double drand48(void)
{
	breakr_action(__FUNCTION__);
}


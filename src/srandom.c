
#include <config.h>
#include <breakr.h>

#include <stdlib.h>

void srandom(unsigned int seed)
{
	breakr_action(__FUNCTION__);
}


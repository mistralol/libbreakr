
#include <config.h>
#include <breakr.h>

#include <stdlib.h>

int rand(void)
{
	breakr_action(__FUNCTION__);
}


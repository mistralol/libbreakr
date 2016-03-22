
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <time.h>

char *ctime(const time_t *timep)
{
	breakr_action(__FUNCTION__);
}


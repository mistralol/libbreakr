
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <time.h>

struct tm *gmtime(const time_t *timep)
{
	breakr_action(__FUNCTION__);
}



#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <time.h>

char *asctime(const struct tm *tm)
{
	breakr_action(__FUNCTION__);
}



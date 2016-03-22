
#include <config.h>
#include <breakr.h>

#include <stdlib.h>

char *ptsname(int fd)
{
	breakr_action(__FUNCTION__);
}


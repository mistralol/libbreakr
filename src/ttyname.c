
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <unistd.h>

char *ttyname(int fd)
{
	breakr_action(__FUNCTION__);
}



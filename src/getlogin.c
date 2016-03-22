
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <unistd.h>

char *getlogin(void)
{
	breakr_action(__FUNCTION__);
}


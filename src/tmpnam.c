
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <stdio.h>

char *tmpnam(char *s)
{
	breakr_action(__FUNCTION__);
}


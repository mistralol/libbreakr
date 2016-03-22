
#include <config.h>
#include <breakr.h>


#include <stdio.h>
#include <sys/types.h>
#include <grp.h>

struct group *fgetgrent(FILE *stream)
{
	breakr_action(__FUNCTION__);
}



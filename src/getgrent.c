
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>

struct group *getgrent(void)
{
	breakr_action(__FUNCTION__);
}


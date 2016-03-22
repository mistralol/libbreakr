
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>

struct group *getgrgid(gid_t gid)
{
	breakr_action(__FUNCTION__);
}



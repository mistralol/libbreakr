
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>

struct group *getgrnam(const char *name)
{
	breakr_action(__FUNCTION__);
}



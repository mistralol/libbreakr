
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwnam(const char *name)
{
	breakr_action(__FUNCTION__);
}


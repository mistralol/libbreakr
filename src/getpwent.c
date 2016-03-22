
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwent(void)
{
	breakr_action(__FUNCTION__);
}


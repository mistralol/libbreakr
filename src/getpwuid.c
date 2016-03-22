
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd *getpwuid(uid_t uid)
{
	breakr_action(__FUNCTION__);
}



#include <config.h>
#include <breakr.h>


#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

struct passwd *fgetpwent(FILE *stream)
{
	breakr_action(__FUNCTION__);
}


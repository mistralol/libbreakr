
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <shadow.h>

struct spwd *getspnam(const char *name)
{
	breakr_action(__FUNCTION__);
}


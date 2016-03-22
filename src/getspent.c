
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <shadow.h>

struct spwd *getspent(void)
{
	breakr_action(__FUNCTION__);
}


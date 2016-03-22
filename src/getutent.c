
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <utmp.h>

struct utmp *getutent(void)
{
	breakr_action(__FUNCTION__);
}


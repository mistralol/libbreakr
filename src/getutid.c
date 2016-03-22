
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <utmp.h>

struct utmp *getutid(const struct utmp *ut)
{
	breakr_action(__FUNCTION__);
}



#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

#include <breakr.h>

enum RunMode
{
	DISABLE,
	LOG,
	SYSLOG,
	ABORT
};

static int active = LOG;

void breakr_activate()
{
	active = DISABLE;
}

void breakr_action(const char *function)
{
	switch(active)
	{
		case DISABLE:
			break;
		case LOG:
			fprintf(stderr, "Illegal call to non thread safe function '%s'\n", function);
			break;
		case SYSLOG:
			syslog(LOG_WARNING, "Illegal call to non thread safe function '%s'\n", function);
			break;
		case ABORT:
			abort();
			break;
	}
}


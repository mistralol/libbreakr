
#include <config.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>

#include <breakr.h>

enum RunMode
{
	DISABLE = 0,
	LOG = 1,
	SYSLOG = 2,
	ABORT = 3
};

static int active = DISABLE;

void breakr_activate()
{
	const char *str = getenv("BREAKR_MODE");
	if (str == NULL)
	{
		active = LOG;
	}
	else
	{
		if (strcmp("0", str) == 0)
			active = DISABLE;
		else if (strcmp("1", str) == 0)
			active = LOG;
		else if (strcmp("2", str) == 0)
			active = SYSLOG;
		else if (strcmp("3", str) == 0)
			active = ABORT;
	}

	switch(active)
	{
		case DISABLE:
			break;
		case LOG:
			fprintf(stderr, "libbreakr now active\n");
			break;
		case SYSLOG:
			syslog(LOG_WARNING, "libbreakr now active");
			break;
		case ABORT:
			break;
	}
}

void breakr_deactive()
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
			syslog(LOG_WARNING, "Illegal call to non thread safe function '%s'", function);
			break;
		case ABORT:
			abort();
			break;
	}
}


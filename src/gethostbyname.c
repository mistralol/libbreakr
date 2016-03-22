
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct hostent *gethostbyname(const char *name)
{
	breakr_action(__FUNCTION__);
}


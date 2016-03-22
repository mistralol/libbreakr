
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct hostent *gethostbyname2(const char *name, int af)
{
	breakr_action(__FUNCTION__);
}


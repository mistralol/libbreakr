
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct servent *getservbyname(const char *name, const char *proto)
{
	breakr_action(__FUNCTION__);
}


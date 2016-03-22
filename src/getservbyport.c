
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct servent *getservbyport(int port, const char *proto)
{
	breakr_action(__FUNCTION__);
}


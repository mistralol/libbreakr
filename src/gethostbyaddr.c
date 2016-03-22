
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type)
{
	breakr_action(__FUNCTION__);
}


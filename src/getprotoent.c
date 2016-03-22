
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct protoent *getprotoent(void)
{
	breakr_action(__FUNCTION__);
}


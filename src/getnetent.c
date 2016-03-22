
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct netent *getnetent(void)
{
	breakr_action(__FUNCTION__);
}


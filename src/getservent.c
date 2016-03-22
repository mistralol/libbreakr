
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct servent *getservent(void)
{
	breakr_action(__FUNCTION__);
}


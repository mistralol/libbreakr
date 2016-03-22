
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <netdb.h>

struct hostent *gethostent(void)
{
	breakr_action(__FUNCTION__);
}


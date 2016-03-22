
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <unistd.h>

char *crypt(const char *key, const char *salt)
{
	breakr_action(__FUNCTION__);
}


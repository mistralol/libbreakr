
#include <config.h>
#include <breakr.h>


#include <stdlib.h>
#include <shadow.h>

struct spwd *fgetspent(FILE *fp)
{
	breakr_action(__FUNCTION__);
}


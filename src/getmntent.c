
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <stdio.h>
#include <mntent.h>

struct mntent *getmntent(FILE *fp)
{
	breakr_action(__FUNCTION__);
}


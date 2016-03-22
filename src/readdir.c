
#include <config.h>
#include <breakr.h>

#include <stdlib.h>
#include <dirent.h>

struct dirent *readdir(DIR *dirp)
{
	breakr_action(__FUNCTION__);
}


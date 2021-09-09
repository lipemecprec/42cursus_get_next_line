#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	int i = 0;
	fd = open("dummy.txt", O_RDONLY);
	// while (i < 2)
	{
		printf("\nNa main > %s", get_next_line(fd));
		i++;
	}
	return (0);
}

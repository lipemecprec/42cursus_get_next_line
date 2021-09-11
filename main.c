#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd;
	int i = 0;
	char *line;

	fd = open("dummy.txt", O_RDONLY);
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("\nNa main > %s", line);
		free(line);
		printf("-------------------------------------------\n");
		i++;
	}
	return (0);
}

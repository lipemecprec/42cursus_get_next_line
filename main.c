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
	while (i < 11)
	{
		line = get_next_line(fd);
		printf("RETURN > %s", line);
		free(line);
		line = NULL;
		printf("-------------------------------------------\n");
		i++;
	}
	return (0);
}

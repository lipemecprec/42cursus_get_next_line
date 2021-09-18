#include <stdio.h>
// malloc
#include <stdlib.h>
// read & write
#include <unistd.h>
// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "get_next_line_bonus.h"

char *gnl(int fd);

int main(void)
{
	int fd1;
	int fd2;
	int fd3;
	int i;
	char *line;

	fd1 = open("dummy.txt", O_RDONLY);
	fd2 = open("dummy2.txt", O_RDONLY);
	fd3 = open("dummy3.txt", O_RDONLY);
	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd1);
		printf("fd1 > %s\n", line);
		free (line);
		line = get_next_line(fd2);
		printf("fd2 > %s\n", line);
		free (line);
		line = get_next_line(fd3);
		printf("fd3 > %s\n", line);
		free (line);
		i++;
	}
}

// char *gnl(int fd)
// {
// 	char	*buf;
// 	int		size;

// 	size = 10;
// 	buf = (char *)malloc(size);
// 	read(fd, buf, size);
// 	buf[size] = '\0';
// 	// write(1, buf, 8);
// 	return (buf);
// }

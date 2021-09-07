#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);

int	main(void)
{
	int fd;

	fd = open("dummy.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	return 0;
}

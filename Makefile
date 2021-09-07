SRCS = get_next_line.c	get_next_line_utils.c	main.c

all: fclean
	gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 ${SRCS}

run: fclean all
	./a.out

fclean:
	rm -rf *.o *.a

SIZE = 8

all: get_next_line.c get_next_line_utils.c libgnl.a
	@gcc get_next_line.c get_next_line_utils.c main.c -L . get_next_line.h -D BUFFER_SIZE=${SIZE} -o gnl

gnl.o: get_next_line.c
	@gcc -c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=${SIZE}

libgnl.a: gnl.o
	@ar rcs libgnl.a get_next_line.o

clean:
	@rm -f get_next_line.o get_next_line_utils.o

fclean: clean
	@rm -f get_next_line.a gnl

re: fclean all

run: fclean all
	./gnl

.PHONY: all clean fclean re run

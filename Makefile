SIZE = 4

all: get_next_line.c get_next_line_utils.c libgnl.a
	@gcc get_next_line.c get_next_line_utils.c main.c -L . get_next_line.h -D BUFFER_SIZE=${SIZE} -o gnl

gnl.o: get_next_line.c
	@gcc -c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=${SIZE}

libgnl.a: gnl.o
	@ar rcs libgnl.a get_next_line.o

clean:
	@rm -f get_next_line.o get_next_line_utils.o
	@rm -f *.o *.a *.out

fclean: clean
	@rm -f get_next_line.a gnl

re: fclean all

run: fclean all
	./gnl

bonus:
	@rm -f *.o *.a *.out
	@gcc -c get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=${SIZE}
	@ar rcs libgnl.a get_next_line_bonus.o
	@gcc get_next_line_bonus.c get_next_line_utils_bonus.c gnl_test.c -L . get_next_line_bonus.h -D BUFFER_SIZE=${SIZE} -g -o gnl
	./gnl

.PHONY: all clean fclean re run

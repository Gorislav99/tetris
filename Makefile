NAME = fillit
SRC = fillit.c entry.c more_function.c search.c transposition.c validator_tetrimino.c
OBJ = fillit.o entry.o more_function.o search.o transposition.o validator_tetrimino.o
FLAG = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):
	@gcc $(FLAG) -c $(SRC)
	@gcc $(OBJ) -o $(NAME)
clean:
	@/bin/rm -f $(OBJ)
fclean: clean
	@/bin/rm -f $(NAME)
re: fclean all clean
##
## EPITECH PROJECT, 2021
## Bistro-Matic
## File description:
## Makefile
##

CC	=	gcc
FLAG=	-W -Wall -Wextra -ggdb -g3

SRC	=	main.c \
		infin_div.c \
		bistro.c \
		eval_expr.c \
		infin_add.c \
		infin_mul.c \
		infin_sub.c \
		infin_mod.c \
		mainc_comp.c \
		opti.c

OBJ = $(SRC:.c=.o)

BIN	=	calc

LIB	=	./lib/libmy.a

all : $(BIN)

$(BIN) : $(OBJ) $(LIB)
	$(CC) -o $(BIN) $(OBJ) -L./lib -lmy

$(OBJ) : $(SRC)
	gcc -c $(SRC) $(FLAG)

$(LIB) :
	make -C ./lib/my

clean :
	rm -rf $(OBJ)

fclean : clean
	make -C ./lib/my/ fclean
	rm -rf $(BIN)
	rm -rf $(LIB)

re : fclean all

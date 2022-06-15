##
## EPITECH PROJECT, 2021
## Day11
## File description:
## makefile
##

CC			= 	gcc
FLAG=	-W -Wall -Wextra

all: build

build:
	$(CC) *.c -c
	ar rsc libmy.a *.o
	cp libmy.a ../

clean:
	rm -rf *.o
	rm -rf *.a

fclean: clean

re: fclean all

##
## EPITECH PROJECT, 2019
## bsq
## File description:
## Makefile
##

SRC	=	*.c

OBJ	=	libmy.a

all	:	$(OBJ)

$(OBJ)	:
	gcc -c -g3 lib/my/$(SRC)
	ar rc $(OBJ) *.o
	gcc -o bsq bsq_main.c bsq_calc.c bsq_handle.c -L. -lmy -I include -g3

clean	:
	rm -f *.o $(OBJ)

fclean	: clean
	rm -f bsq

re	: fclean all

tests_run :
	gcc -c lib/my/$(SRC)
	ar rc $(OBJ) *.o
	gcc -o units bsq_main.c tests/bsq_main_test.c -L. -lmy --coverage -lcriterion -I include
	./units

coverage :
	gcovr --exclude test/

test_clean :
	rm -f *.gcno
	rm -f *.gcda
	rm -f *.o
	rm -f units
##
## EPITECH PROJECT, 2019
## makefile criterion
## File description:
## units tests
##

SRC=		./src/args.c		\
			./src/free.c		\
			./src/malloc.		\
			./src.nodes.c		\
			./src.realloc.c		\
			./utils.c

REQUIRF	=	./src/args.c		\
			./src/free.c		\
			./src/malloc.		\
			./src.nodes.c		\
			./src.realloc.c		\
			./utils.c

UNITFLAGS	=	-lcriterion -lgov	--coverage

REQTU	=	./test/tests_criterion_malloc.c

OBJ=			$(SRC:.c=.o)

CFLAGS=		-W -Wall -Wextra -pedantic -g3

NAME=		malloc

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ) $(LFLAGS) $(CFLAGS)

clean:
						rm -f $(OBJ) *~ \#*\# *.gc*

show_coverage:
							gcc -o units $(UNITFLAGS) $(CFLAGS) $(REQTU) $(REQUIRF)
							./units
							gcov *.gcda

fclean:			clean
				rm -f $(NAME) units

re:				fclean all
				

##
## EPITECH PROJECT, 2019
## makefile criterion
## File description:
## units tests
##

NAME	=	unit_tests

CC		=	gcc

SRC		=	./free.c	\
			./malloc.c 	\
			./realloc.c

OBJ		=	$(SRC:.c=.o)

CFLAGS	+=	-W	-Wall -Wextra -Wpedantic -Werror
CFLAGS	+=	-std=gnull -I./tests/include

NAME_UT	=	unit_tests

SRC_UT	=	./test/test_criterion_malloc.c

LDFLAGS_UT	=	-lcriterion  -lgov --coverage

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)
		
tests_run:
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS_UT)
	./$(NAME_UT) -j0 --always-succeed


clean:
	$(RM) $(OBJ) $(SRC_UT:.c=.o) $(SRC_UT:.c=.gcda) $(SRC_UT:.c=.gcno)
	$(RM) *~ \#*\# vgcore.* .gdb_history peda-session-* *.g*

fclean:	clean
		$(RM) $(NAME) a.out *.o *.a *.session

re:		fclean all

.PHONY:	all clean fclean re tests run
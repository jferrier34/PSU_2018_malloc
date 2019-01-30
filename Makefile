##
## EPITECH PROJECT, 2019
## PSU_2018_malloc
## File description:
## Makefile
##

SRC_DIR		=	$(realpath ./src)

SRC		=	$(SRC_DIR)/malloc.c	\
			$(SRC_DIR)/nodes.c	\
			$(SRC_DIR)/free.c	\
			$(SRC_DIR)/realloc.c \
			$(SRC_DIR)/utils.c

CFLAGS		=	-W -Wall -I./include -ggdb3
LDFLAGS 	=	-lpthread -fPIC -ggdb3 -shared

NAME		=	libmy_malloc.so

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(SRC) -I./include $(LDFLAGS)

debug:		$(OBJ)
		gcc -o $(NAME) $(SRC) -I./include $(LDFLAGS)

clean:
		rm -f $(OBJ)
		rm -f $(SRC_DIR)/*~

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all debug clean fclean re



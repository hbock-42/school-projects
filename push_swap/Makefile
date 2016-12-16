NAME =		push_swap

SRC	=		src/algo.c \
			src/error.c \
			src/ft_atoi.c\
			src/ope.c \
			src/pushswap.c \
			src/tools.c

OBJ =		$(SRC:.c=.o)

CC =		gcc
CFLAGS =	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
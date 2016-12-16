NAME = fdf

# ------------------------ Sources path ----------------------------------------------------
SRC_NAME			= ./src/calc_fdf.c \
					  ./src/create_int_map.c \
					  ./src/draw_fdf.c \
					  ./src/env.c \
					  ./src/error.c \
					  ./src/event.c \
					  ./src/get_map.c \
					  ./src/image.c \
					  ./src/line.c \
					  ./src/line_axes.c \
					  ./src/main.c \
					  ./src/map_actions.c \
					  ./src/usage.c

# ------------------------ Dependencies path ------------------------------------------------
DEPENDENCIES 	= ./dependencies/

OBJ_NAME		= $(SRC_NAME:.c=.o)

LMLX			= minilibx_macos/
LMLXPATH		= $(addprefix $(DEPENDENCIES), $(LMLX))
LMLXFLAG		= -L $(LMLXPATH) -lmlx -framework OpenGL -framework AppKit

LIBFTPATH		= ./libft/
LIBFTFLAG		= -L $(LIBFTPATH) -lft

# ------------------------ Compiler ---------------------------------------------------------
CC 				= gcc
CFLAGS			= -Wall -Werror -Wextra

# -------------------------------------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJ_NAME)
	@make -C libft/
	@make -C $(LMLXPATH)
	@echo "creating fdf"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_NAME) $(LIBFTFLAG) $(LMLXFLAG)

clean:
	@make clean -C ./libft
	@make clean -C ./dependencies/minilibx_macos/
	@echo "cleaning fdf objects"
	@rm -rf $(OBJ_NAME)

fclean: clean
	@echo "cleaning fdf"
	@rm -f $(NAME)
	@rm -f $(OBJ_NAME)
	@make fclean -C ./libft

re:	fclean all

.PHONY: all, clean, fclean, re, libft

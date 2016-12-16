NAME = rtv1

# ------------------------ Sources path ----------------------------------------------------
SRC_NAME			= ./src/color.c \
					  ./src/draw.c \
					  ./src/env.c \
					  ./src/error.c \
					  ./src/event.c \
					  ./src/intersection.c \
					  ./src/main.c \
					  ./src/obj_parse_0.c \
					  ./src/obj_parse_1.c \
					  ./src/parse_check_params.c \
					  ./src/raylaunch.c \
					  ./src/read_scene.c \
					  ./src/read_scene_tools.c \
					  ./src/shadow.c \
					  ./src/vector_calc_0.c \
					  ./src/vector_calc_1.c \
					  ./src/vector_calc_2.c

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
	@echo "creating rtv1"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_NAME) $(LIBFTFLAG) $(LMLXFLAG)

clean:
	@make clean -C ./libft
	@make clean -C ./dependencies/minilibx_macos/
	@echo "cleaning rtv1 objects"
	@rm -rf $(OBJ_NAME)

fclean: clean
	@echo "cleaning rtv1"
	@rm -f $(NAME)
	@rm -f $(OBJ_NAME)
	@make fclean -C ./libft

re:	fclean all

.PHONY: all, clean, fclean, re
.SILENT: $(OBJ_NAME)

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbock <hbock@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/09 20:46:08 by hbock             #+#    #+#              #
#    Updated: 2015/06/09 20:46:09 by hbock            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

# ---------------------- Sources path ------------------------------------------
SRC_PATH = ./src/
SRC_NAME =	color.c \
			default_reading.c \
			draw.c \
			env.c \
			event.c \
			ft_strsplit.c \
			image.c \
			lib.c \
			player_move.c \
			reallocat.c \
			wolf.c \
			wolf_main.c

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))

# ---------------------- Dependencies path -------------------------------------
DEPENDENCIES = ./dependencies/

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

LMLX = minilibx_macos/
LMLXPATH = $(addprefix $(DEPENDENCIES), $(LMLX))
LMLXFLAG = -L $(LMLXPATH) -lmlx -framework OpenGL -framework AppKit

# ---------------------- Compiler ----------------------------------------------
CC = gcc
CFLAG = -Wall -Wextra -Werror

# ---------------------- Dependencies path--------------------------------------
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LMLXPATH)
	@echo "\033[35;1m• \033[0mCreating \033[35m$(NAME)\033[0m ...\033[55G\c"
	@export result=`$(CC) -o $(NAME) $(OBJ) $(LMLXFLAG)` ; \
	if [ "$$result" = "" ] ; then \
		echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m" ; \
	else \
		echo "\033[37;1m[\033[31mFAIL\033[37m]\033[0m" ; \
		echo "\n$$result" ; \
		exit 1 ; \
	fi

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@echo "\033[35;1m• \033[0mCreating \033[35m$(NAME)\033[0m object file...\033[55G\c"
	@export result=`$(CC) $(CFLAG) $(INC) -o $@ -c $<` ; \
	if [ "$$result" = "" ] ; then \
		echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m" ; \
	else \
		echo "\033[37;1m[\033[31mFAIL\033[37m]\033[0m" ; \
		echo "\n$$result" ; \
		exit 1 ; \
	fi

clean:
	@make clean -C $(LMLXPATH)
	@echo "\033[35;1m• \033[0mRemoving \033[35m$(NAME)\033[0m object files ...\033[55G\c"
	@rm -rf $(OBJ)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@make clean -C $(LMLXPATH)
	@echo "\033[35;1m• \033[0mRemoving \033[35m$(NAME)\033[0m ...\033[55G\c"
	@rm -f $(NAME)
	@echo "\033[37;1m[\033[32mOK !\033[37m]\033[0m"

re: fclean all

norme:
	norminette $(SRC)

.PHONY: all, clean, fclean, re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 19:36:18 by antmoren          #+#    #+#              #
#    Updated: 2023/03/14 19:49:43 by antmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBMLX	=	./lib/MLX42
LIBFT	=	./lib/42-library
HEADERS	=	-I ./include -I $(LIBMLX)/include -I $(LIBFT)
#LIBS	=	-lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/42lib.a 
LIBS	=	-lglfw -L /opt/homebrew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/42lib.a

SRC_PATH 		= 	./src/
OBJ_PATH 		= 	./obj/

SRCS	= 	main.c				\
			check_map_utils.c	\
			check_map.c 		\
			map.c 				\
			movement.c 			\
			textures.c 			\
			utils.c 			\

OBJS 	= $(addprefix $(OBJ_PATH), $(SRCS:.c=.o))



BOLD	=	\033[1m
BLACK	=	\033[30;1m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YELLOW	=	\033[33;1m
BLUE	=	\033[34;1m
MAGENTA	=	\033[35;1m
CYAN	=	\033[36;1m
WHITE	=	\033[37;1m
RESET	=	\033[0m

all: libft libmlx $(OBJ_PATH) $(NAME)

libft:
	@$(MAKE) -C $(LIBFT)

libmlx:
	@$(MAKE) -C $(LIBMLX)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(INCS) $(HEADERS) -c $< -o $@

$(OBJ_PATH): 
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "\n 👾 $(NAME) compiled! ✅"

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	@echo "\n  👾 $(NAME) executable files removed! 🗑"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean
	@echo "\n  👾 $(NAME) generated files removed! 🗑"

re: clean all
	@echo "\n 🔄  ✅ Cleaned and rebuilt everything from Fdf"

.PHONY: all, clean, fclean, re, libmlx, libft
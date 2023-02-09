# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 19:36:18 by antmoren          #+#    #+#              #
#    Updated: 2023/02/08 12:03:46 by antmoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= FDF
CFLAGS	= -Wall -Wextra -Werror
LIBMLX	= ./lib/MLX42
LIBFT	= ./lib/42-library

HEADERS	= -I ./include -I $(LIBMLX)/include -I $(LIBFT)
#LIBS	= -lglfw -L /Users/$(USER)/.brew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/42lib.a 
LIBS	= -lglfw -L /opt/homebrew/opt/glfw/lib/ $(LIBMLX)/libmlx42.a $(LIBFT)/42lib.a
SRCS	= $(shell find ./src -iname "*.c")
OBJS	= ${SRCS:.c=.o}

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
GREEN	= \033[32;1m
YELLOW	= \033[33;1m
BLUE	= \033[34;1m
MAGENTA	= \033[35;1m
CYAN	= \033[36;1m
WHITE	= \033[37;1m
RESET	= \033[0m

# //= Recipes =//

all: libft libmlx $(NAME)
	@echo "hey"

libft:
	@$(MAKE) -C $(LIBFT)
	@echo "\n 📚 42 Library compiled! ✅"

libmlx:
	@$(MAKE) -C $(LIBMLX)
	@echo "\n 💻 MLX42 compiled! ✅"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "\n ⛓️  Fdf compiled! ✅"

clean:
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(LIBMLX) clean
	@echo "\n ⛓️  Fdf executable files removed! 🗑"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(LIBMLX) fclean
	@echo "\n ⛓️  Fdf generated files removed! 🗑"

re: clean all
	@echo "\n 🔄  ✅ Cleaned and rebuilt everything from Fdf"

.PHONY: all, clean, fclean, re, libmlx, libft
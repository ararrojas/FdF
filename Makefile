# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arojas-a <arojas-a@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 14:33:46 by arojas-a          #+#    #+#              #
#    Updated: 2024/09/13 16:19:21 by arojas-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		:= fdf

CC		:= cc
CFLAGS		:= -Wextra -Wall -Werror -Ofast -g

MLX_DIR 	:= ./lib/MLX42
MLX			:= $(MLX_DIR)/build/libmlx42.a
LIBFT_DIR	:= ./lib/libft
LIBFT		:= $(LIBFT_DIR)/libft.a

HEADERS		:= -I $(MLX_DIR)/include/MLX42 -I $(LIBFT_DIR)
LIBS		:= -L$(LIBFT_DIR) -lft  $(MLX_DIR)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS		:= $(wildcard *.c)
OBJS		:= ${SRCS:.c=.o}

all: $(NAME)

#          COLORS          #
END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m

$(MLX): $(MLX_DIR)
	cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

$(MLX_DIR):
	git clone https://github.com/42-Fundacion-Telefonica/MLX42.git $@

$(LIBFT_DIR):
	git clone https://github.com/ararrojas/libft.git $@

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c fdf.h
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)  
	@echo "\n $(GREEN) ===== FdF compiled! ===== $(END)\n"

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)
	@echo "\n$(CIAN) ===== FdF and Libft object files cleaned :) ===== $(END)\n"

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_DIR)
	rm -rf $(MLX_DIR)
	@echo "\n$(YELLOW) ===== $(NAME) executable files and name cleaned! ===== $(END)\n"
	@echo "\n$(CIAN) ===== Libft and MLX42 erased! ===== $(END)\n"

re: fclean all

.PHONY: all, clean, fclean, re, mlx, libft

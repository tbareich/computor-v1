# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 10:39:00 by tbareich          #+#    #+#              #
#    Updated: 2022/04/16 13:31:43 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh

NAME := mathft.a

SRCS_DIR := srcs/
OBJS_DIR := objs/
INCLUDES_DIR = includes/

HEADER := $(INCLUDES_DIR)mathft.h
SRCS := ft_sqrt.c ft_pow.c ft_abs.c ft_nan.c ft_root.c ft_max.c ft_min.c \
	ft_gcd.c ft_round.c ft_floor.c ft_ceil.c to_fraction.c
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CFLAGS := -Wall -Wextra -Werror
CC := gcc

# Colors
GREEN := \033[1;32m
RED := \033[1;31m
BLUE := \033[1;34m
WHITE := \033[1;37m
WHITE := \033[1;37m
GREY := \033[1;249m
RESET := \033[0m


all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@ar rc $(NAME) $(OBJS) 
	@echo "\n$(GREEN)$(NAME): created ✔$(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDES_DIR)
	@echo "$(WHITE).\c$(RESET)"

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
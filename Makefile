# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 09:37:08 by tbareich          #+#    #+#              #
#    Updated: 2022/03/31 10:21:59 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh

NAME := computor

SRCS_DIR := src/
OBJS_DIR := obj/
INCLUDES_DIR = includes/

HEADER := $(INCLUDES_DIR)computor.h
SRCS := main.c
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CFLAGS := -Wall -Wextra -Werror
CC := gcc

# Colors
GREEN				:= \033[1;32m
RED					:= \033[1;31m
BLUE				:= \033[1;34m
WHITE				:= \033[1;37m
WHITE				:= \033[1;37m
GREY				:= \033[1;249m
RESET				:= \033[0m


all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(INCLUDES_DIR)
	@echo "\n$(GREEN)computor-v1: linked$(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c -o $@ $< -I$(INCLUDES_DIR)
	@echo "$(GREY).\c$(RESET)"

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
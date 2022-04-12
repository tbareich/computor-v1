# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/31 09:37:08 by tbareich          #+#    #+#              #
#    Updated: 2022/04/11 21:08:58 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL:=/bin/zsh

NAME := computor
MATHFT := mathft

MATHFT_DIR := mathft/
SRCS_DIR := srcs/
OBJS_DIR := objs/
INCLUDES_DIR = includes/

MATHFT_LIB := $(MATHFT_DIR)mathft.a
HEADERS := -I$(INCLUDES_DIR) -I$(MATHFT_DIR)$(INCLUDES_DIR)

HEADER := $(INCLUDES_DIR)computor.h
SRCS := main.cpp reader.cpp usage.cpp
OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# CFLAGS := -Wall -Wextra -Werror
CC := g++

# Colors
GREEN := \033[1;32m
RED := \033[1;31m
BLUE := \033[1;34m
WHITE := \033[1;37m
WHITE := \033[1;37m
GREY := \033[1;249m
RESET := \033[0m


all: $(MATHFT) $(NAME)

$(NAME): $(MATHFT_LIB) $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(MATHFT_LIB) $(OBJS) -o $(NAME) $(HEADERS)
	@echo "\n$(GREEN)$(NAME): created ✔$(RESET)"

$(MATHFT):
	@$(MAKE) -C $(MATHFT_DIR)

$(MATHFT_LIB):
	@$(MAKE) -C $(MATHFT)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS)
	@echo "$(WHITE).\c$(RESET)"

clean:
	@$(MAKE) clean -C $(MATHFT)
	@rm -rf $(OBJS_DIR)

fclean: clean
	@$(MAKE) fclean -C $(MATHFT)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re $(MATHFT)
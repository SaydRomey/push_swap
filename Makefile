# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 17:43:39 by cdumais           #+#    #+#              #
#    Updated: 2023/06/19 20:12:27 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# -------------------------------- C FILES ----------------------------------- #
# **************************************************************************** #
SRC	=																		   \
main.c			parse_args.c							new_stack.c			   \
push_swap.c		parse_quoted_args.c						stack_is_empty.c	   \
														stack_is_sorted.c	   \
sort_2.c		sort_more.c		st_push.c				stack_size.c		   \
sort_3.c		st_max.c		st_pop.c									   \
sort_4.c		st_min.c		st_swap.c									   \
sort_5.c						st_rotate.c									   \
sort_less_utils.c				st_reverse_rotate.c							   \
															index.c			   \
stack_to_simplified_binary.c	stack_to_array.c			free_stack.c	   \
								rank_stack_values.c			free_split.c	   \
								convert_to_binary.c							   \
								replace_stack_values.c		exit_error.c
# **************************************************************************** #
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# **************************************************************************** #
# ------------------------------- VARIABLES ---------------------------------- #
# **************************************************************************** #
NAME = push_swap

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
LIBFT_DIR = libft

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/$(SRC_DIR)/*.c)

# SRCS = $(wildcard $(SRC_DIR)/*.c)
# OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I$(LIBFT_DIR)/$(INC_DIR) -I$(INC_DIR)

RMF = rm -f
RMD = rm -rf

NPD = --no-print-directory

# **************************************************************************** #
# --------------------------------- RULES ------------------------------------ #
# **************************************************************************** #
all: $(NAME)
	@echo "$(PURPLE)$(BOLD)\ncdumais's$(RESET)"
	@echo "$(GREEN)$$TITLE$(RESET)"
	@echo "Executed by $(ITALIC)$(BOLD)$(PURPLE)$(USER)$(RESET) \
						    $(CYAN)$(TIME)$(RESET)\n"

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@
	@echo "$(BOLD)$(PURPLE)$(ERASE)push_swap $(GREEN)ready !$(RESET)"

libft: $(LIBFT)

$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) -C $(LIBFT_DIR) $(NPD)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)$(BOLD)Compiling $(RESET)$(CYAN)$(notdir $<)$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf $(UP)$(CUT)

clean:
	@if [ -n "$(wildcard $(OBJ_DIR)/*.o)" ]; then \
		$(RMD) $(OBJ_DIR); \
		echo "$(GREEN)Object files removed$(RESET)"; \
	else \
		echo "$(YELLOW)No object files to remove$(RESET)"; \
	fi

fclean: clean
	@if [ -n "$(wildcard $(NAME))" ]; then \
		$(RMF) $(NAME); \
		echo "$(BOLD)$(PURPLE)$(NAME)$(RESET)$(GREEN) removed"; \
	else \
		echo "$(YELLOW)No executable to remove$(RESET)"; \
	fi

re: fclean all

# **************************************************************************** #
# ------------------------------ NORMINETTE ---------------------------------- #
# **************************************************************************** #
norm:
	norminette -R CheckForbiddenSourceHeader src/*.c
	norminette -R CheckDefine inc/*.h

# **************************************************************************** #
# -------------------------------- LEAKS ------------------------------------- #
# **************************************************************************** #
# leaks: all
# 	leaks --atExit -- ./push_swap "6 5 4 3 2 1"

leaks: all
	leaks --atExit -- ./push_swap 6 5 4 3 2 1

# **************************************************************************** #
# -------------------------------- VISUAL ------------------------------------ #
# **************************************************************************** #
visual: all
	./push_swap_visualizer/build/bin/visualizer

visualclone:
	git clone https://github.com/o-reo/push_swap_visualizer && \
	cd push_swap_visualizer && \
	mkdir -p build && \
	cd build && \
	cmake .. && \
	make

visualclean:
	$(RMD) push_swap_visualizer
	$(RMF) imgui.ini

# **************************************************************************** #
# --------------------------------- MISC ------------------------------------- #
# **************************************************************************** #
pdf:
	@open https://projects.intra.42.fr/42cursus-push_swap/cdumais
	@open https://cdn.intra.42.fr/pdf/pdf/80702/en.subject.pdf

numbers:
	@open https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php

# **************************************************************************** #
# ------------------------------- CHECKER ------------------------------------ #
# **************************************************************************** #
checker:
	@if [ "$(OS)" = "Darwin" ]; then \
		echo "Downloading $(BOLD)$(ORANGE)checker_Mac$(RESET)..."; \
		curl -o checker_OS https://cdn.intra.42.fr/document/document/15403/checker_Mac; \
	elif [ "$(OS)" = "Linux" ]; then \
		echo "Downloading $(BOLD)$(ORANGE)checker_Linux$(RESET)..."; \
		curl -o checker_OS https://cdn.intra.42.fr/document/document/15404/checker_linux; \
	else \
		echo "Checker not available for: $(OS)"; \
		exit 1; \
	fi
	@chmod +x checker_OS

# **************************************************************************** #
# ---------------------------------- SHELL ----------------------------------- #
# **************************************************************************** #
OS			=$(shell uname)
USER		=$(shell whoami)
DATE		=$(shell date "+%d/%m/%y")
TIME		=$(shell date "+%H:%M:%S")

# **************************************************************************** #
# ---------------------------------- COLORS ---------------------------------- #
# **************************************************************************** #
# ** Text 
BLACK		=\033[30m
RED			=\033[31m
GREEN		=\033[32m
YELLOW		=\033[33m
BLUE		=\033[34m
PURPLE		=\033[35m
CYAN		=\033[36m
WHITE		=\033[37m
# **
BR_YELLOW	=\033[38;5;226m
ORANGE		=\033[38;5;208m
RED_ORANGE	=\033[38;5;202m

# ** Tools
ERASE		=\033[2K
RESET		=\033[0m
BOLD		=\033[1m
FAINT		=\033[2m
ITALIC		=\033[3m
UNDERLINE	=\033[4m
# BLINK		=\033[5m #no effect on iterm?
INVERT		=\033[7m
STRIKE		=\033[9m

# ** Background(BG)
BG_BLACK	=\033[40m
BG_RED		=\033[41m
BG_GREEN	=\033[42m
BG_YELLOW	=\033[43m
BG_BLUE		=\033[44m
BG_PURPLE	=\033[45m
BG_CYAN		=\033[46m
BG_WHITE	=\033[47m

# ** Misc (with printf)
UP			="\033[A" #cursor up
CUT			="\033[K" #cut line

# **************************************************************************** #
# ------------------------------- DECORATIONS -------------------------------- #
# **************************************************************************** #
define TITLE

██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ 
██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗
██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝
██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ 
██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     
╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     

endef
export TITLE

# **************************************************************************** #
# ----------------------------------- PHONY ---------------------------------- #
# **************************************************************************** #
.PHONY: all bonus clean fclean re \
		norm leaks \
		visual visualclone visualclean \
		pdf numbers checker

# **************************************************************************** #
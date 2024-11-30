# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 17:43:39 by cdumais           #+#    #+#              #
#    Updated: 2024/11/29 23:27:27 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap
AUTHOR		:= cdumais

COMPILE		:= gcc
CFLAGS		:= -Wall -Wextra -Werror

INC_DIR		:= inc
INCLUDES	:= -I$(INC_DIR)

SRC_DIR		:= src
OBJ_DIR		:= obj

LIBFT_DIR	:= libft
LIBFT		:= $(LIBFT_DIR)/libft.a
INCLUDES	+= -I$(LIBFT_DIR)/$(INC_DIR)

TMP_DIR		:= tmp

REMOVE		:= rm -rf
NPD			:= --no-print-directory
VOID		:= /dev/null
OS			:=$(shell uname)
USER		:=$(shell whoami)
DATE		:=$(shell date "+%d/%m/%y")
TIME		:=$(shell date "+%H:%M:%S")

# **************************************************************************** #
# --------------------------------- H FILES ---------------------------------- #
# **************************************************************************** #
INC	:=			push_swap
# **************************************************************************** #
# -------------------------------- C FILES ----------------------------------- #
# **************************************************************************** #
SRC	:=																		   \
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
# --------------------------------- ALL FILES -------------------------------- #
# **************************************************************************** #
INCS	:= $(addprefix $(INC_DIR)/, $(addsuffix .h, $(INC)))
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
# **************************************************************************** #
# -------------------------------- ALL * FILES ------------------------------- #
# **************************************************************************** #
# INCS	:=	$(wildcard $(INC_DIR)/*.h)
# SRCS	:=	$(wildcard $(SRC_DIR)/*.c)
# OBJS	:=	$(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%.o, $(SRCS))
# **************************************************************************** #
# --------------------------------- RULES ------------------------------------ #
# **************************************************************************** #
.DEFAULT_GOAL	:= all

.DEFAULT: ## Handle invalid targets
	$(info make: *** No rule to make target '$(MAKECMDGOALS)'.  Stop.)
	@$(MAKE) help $(NPD)

all: $(NAME) ## Compile executable

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@
	@echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)]\\t$(GREEN)created$(RESET)"
	@$(MAKE) title

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(CYAN)Compiling...$(ORANGE)\t$(notdir $<)$(RESET)"
	@$(COMPILE) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(UP)$(ERASE_LINE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

libft: $(LIBFT) ## Compile libft

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) $(NPD)

clean: ## Remove object files
	@if [ -n "$(wildcard $(OBJ_DIR))" ]; then \
		$(REMOVE) $(OBJ_DIR); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Object files removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No object files to remove$(RESET)"; \
	fi

fclean: clean ## 'clean' + Remove executable
	@if [ -n "$(wildcard $(NAME))" ]; then \
		$(REMOVE) $(NAME); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No executable to remove$(RESET)"; \
	fi

re: fclean all ## Recompile the project

.PHONY: all libft clean fclean re
# **************************************************************************** #
# ---------------------------------- UTILS ----------------------------------- #
# **************************************************************************** #
help: ## Display available targets
	@echo "\nAvailable targets:"
	@awk 'BEGIN {FS = ":.*##";} \
		/^[a-zA-Z_0-9-]+:.*?##/ { \
			printf "  $(CYAN)%-15s$(RESET) %s\n", $$1, $$2 \
		} \
		/^##@/ { \
			printf "\n$(BOLD)%s$(RESET)\n", substr($$0, 5) \
		}' $(MAKEFILE_LIST)

ARGS	:= 6 5 4 3 2 1
# ARGS	:= "6 5 4 3 2 1"

run: all ## Compile and run executable with arbitrary argument
	@./$(NAME) $(ARGS)

leaks: all ## Compile and run executable with arbitrary with minimal check for leaks
	leaks --atExit -- ./$(NAME) $(ARGS)

norm: ## Check norminette on .c and .h files
	@if which norminette > $(VOID); then \
		echo "$(BOLD)$(YELLOW)Norminetting $(PURPLE)$(NAME)$(RESET)"; \
		norminette -o $(INCS); \
		norminette -o $(SRCS); \
		$(MAKE) norm -C $(LIBFT_DIR) $(NPD); \
	else \
		echo "$(BOLD)$(YELLOW)Norminette not installed$(RESET)"; \
	fi

nm: $(NAME) ## Display functions used (formatted output)
	@echo "$(BOLD)$(YELLOW)Functions in $(PURPLE)$(UNDERLINE)$(NAME)$(RESET):"
	@nm $(NAME) | grep U | grep -v 'ft_' \
				| sed 's/U//g' | sed 's/__//g' | sed 's/ //g' \
				| sort | uniq
	@$(MAKE) nm -C $(LIBFT_DIR) $(NPD)

numbers: ## Open a random number generator URL
	@open https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php

ffclean: fclean vclean checker_clean ## Complete cleanup (tmp files, curl'ed executables, etc.)
	@if [ -n "$(wildcard $(TMP_DIR))" ]; then \
		$(REMOVE) $(TMP_DIR) $(TMP_FILES); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Temporary files removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No temporary files to remove$(RESET)"; \
	fi
	@$(MAKE) -C $(LIBFT_DIR) fclean $(NPD)

.PHONY: help run leaks norm nm numbers ffclean
# **************************************************************************** #
# ---------------------------------- PDF ------------------------------------- #
# **************************************************************************** #
PDF		:= push_swap_en.pdf
GIT_URL	:= https://github.com/SaydRomey/42_ressources
PDF_URL	= $(GIT_URL)/blob/main/pdf/$(PDF)?raw=true

$(TMP_DIR):
	@mkdir -p $(TMP_DIR)

pdf: | $(TMP_DIR) ## Opens the PDF instructions
	@curl -# -L $(PDF_URL) -o $(TMP_DIR)/$(PDF)
	@open $(TMP_DIR)/$(PDF) || echo "Please install a compatible PDF viewer"

.PHONY: pdf
# **************************************************************************** #
# --------------------------------- GITHUB ----------------------------------- #
# **************************************************************************** #
REPO_LINK	:= https://github.com/SaydRomey/push_swap

repo: ## Open the GitHub repository for this project
	@echo "Opening $(AUTHOR)'s github repo..."
	@open $(REPO_LINK);

.PHONY: repo
# **************************************************************************** #
# ---------------------------------- BACKUP (zip) ---------------------------- #
# **************************************************************************** #
ROOT_DIR	:=$(notdir $(shell pwd))
TIMESTAMP	:=$(shell date "+%Y%m%d_%H%M%S")
BACKUP_NAME	:=$(ROOT_DIR)_$(USER)_$(TIMESTAMP).zip
MOVE_TO		:= ~/Desktop/$(BACKUP_NAME)

zip: ffclean ## Compress this project as a zip file on Desktop
	@if which zip > $(VOID); then \
		zip -r --quiet $(BACKUP_NAME) ./*; \
		mv $(BACKUP_NAME) $(MOVE_TO); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		compressed as: $(CYAN)$(UNDERLINE)$(MOVE_TO)$(RESET)"; \
	else \
		echo "Please install zip to use the backup feature"; \
	fi

.PHONY: zip
# **************************************************************************** #
# -------------------------------- VISUAL ------------------------------------ #
# **************************************************************************** #
VISUAL_URL		:= https://github.com/o-reo/push_swap_visualizer
VISUAL_DIR		:= push_swap_visualizer
VISUAL_BIN		:= $(VISUAL_DIR)/build/bin/visualizer
VISUAL_EXEC		:= visualizer
VISUAL_CONFIG	:= imgui.ini

visual: all ## build and execute the push_swap visualizer
	@if [ ! -f "$(VISUAL_EXEC)" ]; then \
		echo "Visualizer not found. Building..."; \
		$(MAKE) visual_setup; \
	fi
	@echo "Launching $(BOLD)$(PURPLE)$(VISUAL_EXEC)$(RESET)..."
	@./$(VISUAL_EXEC) || { \
		echo "Error: $(VISUAL_BIN) failed to run. Rebuilding..."; \
		$(REMOVE) $(VISUAL_EXEC); \
		$(MAKE) visual_setup; \
		./$(VISUAL_EXEC); \
	}

visual_setup: ## Clone and build the visualizer -> 'visual' helper target
	@if [ ! -d "$(VISUAL_DIR)" ]; then \
		echo "Cloning vizualiser repository..."; \
		git clone $(VISUAL_URL); \
	fi
	@echo "Building $(VISUAL_BIN)..."; \
	cd $(VISUAL_DIR) && mkdir -p build && cd build && cmake -Wno-dev .. && make
	@cp $(VISUAL_BIN) $(VISUAL_EXEC) || echo "Error: Failed to copy $(VISUAL_BIN) to project root."
	@echo "Build complete. Executable available as $(VISUAL_EXEC)."

vclean: ## Clean up the visualizer and configuration
	@if [ -d "$(VISUAL_DIR)" ] || [ -f "$(VISUAL_BIN)" ] || [ -f "$(VISUAL_CONFIG)" ] || [ -f "$(VISUAL_EXEC)" ]; then \
		echo "Cleaning visualizer files..."; \
		[ -d "$(VISUAL_DIR)" ] && echo "Removing directory: $(VISUAL_DIR)" && $(REMOVE) $(VISUAL_DIR); \
		[ -f "$(VISUAL_BIN)" ] && echo "Removing executable: $(VISUAL_BIN)" && $(REMOVE) $(VISUAL_BIN); \
		[ -f "$(VISUAL_EXEC)" ] && echo "Removing root executable: $(VISUAL_EXEC)" && $(REMOVE) $(VISUAL_EXEC); \
		[ -f "$(VISUAL_CONFIG)" ] && echo "Removing config file: $(VISUAL_CONFIG)" && $(REMOVE) $(VISUAL_CONFIG); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Visualizer files removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No visualizer files to remove$(RESET)"; \
	fi

.PHONY: visual visual_setup vclean
# **************************************************************************** #
# ------------------------------- CHECKER ------------------------------------ #
# **************************************************************************** #
CHECKER			:= checker_OS
MAC_CHECKER		:= utils/checker_Mac
LINUX_CHECKER	:= utils/checker_linux
ARGS			:= 4 67 3 87 23

# (the links might break later..)
# MAC_CHECKER		:= https://cdn.intra.42.fr/document/document/25668/checker_Mac
# LINUX_CHECKER	:= https://cdn.intra.42.fr/document/document/25669/checker_linux

# get_checker: ## Gets the 42's push_swap checker
# 	@if [ -f "$(CHECKER)" ]; then \
# 		echo "$(BOLD)$(GREEN)Checker is already available: $(CHECKER)$(RESET)"; \
# 	else \
# 		if [ "$(OS)" = "Darwin" ]; then \
# 			echo "Downloading $(BOLD)$(ORANGE)checker_Mac$(RESET)..."; \
# 			curl -o $(CHECKER) $(MAC_CHECKER); \
# 		elif [ "$(OS)" = "Linux" ]; then \
# 			echo "Downloading $(BOLD)$(ORANGE)checker_linux$(RESET)..."; \
# 			curl -o $(CHECKER) $(LINUX_CHECKER); \
# 		else \
# 			echo "Error: Checker not available for OS: $(OS)"; \
# 			exit 1; \
# 		fi; \
# 		chmod +x $(CHECKER); \
# 		echo "$(BOLD)$(GREEN)Checker downloaded and ready to use: $(CHECKER)$(RESET)"; \
# 	fi

get_checker: ## Gets checker from utils directory
	@if [ ! -f "$(CHECKER)" ]; then \
		if [ "$(OS)" = "Darwin" ]; then \
			cp $(MAC_CHECKER) ./$(CHECKER) || echo "Error: Failed to copy $(MAC_CHECKER) to project root..."; \
		elif [ "$(OS)" = "Linux" ]; then \
			cp $(LINUX_CHECK) ./$(CHECKERER) || echo "Error: Failed to copy $(LINUX_CHECKER) to project root..."; \
		else \
			echo "Error: Checker not available for OS: $(OS)"; \
			exit 1; \
		fi; \
		chmod +x $(CHECKER); \
		echo "$(GRAYTALIC)$(CHECKER) ready...$(RESET)"; \
	fi

checker: $(NAME) get_checker ## Run push_swap with checker_OS
	@if [ -z "$(ARGS)" ]; then \
		echo "$(BOLD)$(RED)No arguments provided. Use ARGS=\"<numbers>\" make checker$(RESET)"; \
		exit 1; \
	fi
	@echo "$(GRAYTALIC)./$(NAME) \"$(ARGS)\" | ./$(CHECKER) \"$(ARGS)\"$(RESET)"
	@./$(NAME) $(ARGS) | ./$(CHECKER) $(ARGS)

checker_clean: ## Removes the checker_OS
	@if [ -f "$(CHECKER)" ]; then \
		$(REMOVE) $(CHECKER); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)$(CHECKER) removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No checker to remove$(RESET)"; \
	fi

.PHONY: get_checker checker checker_clean
# **************************************************************************** #
# ----------------------------------- ANSI ----------------------------------- #
# **************************************************************************** #
ESC			:= \033

# Text
RESET		:= $(ESC)[0m
BOLD		:= $(ESC)[1m
ITALIC		:= $(ESC)[3m
UNDERLINE	:= $(ESC)[4m

RED			:= $(ESC)[91m
GREEN		:= $(ESC)[32m
YELLOW		:= $(ESC)[93m
ORANGE		:= $(ESC)[38;5;208m
BLUE		:= $(ESC)[94m
PURPLE		:= $(ESC)[95m
CYAN		:= $(ESC)[96m
GRAYTALIC	:= $(ESC)[3;90m

# Cursor movement
UP			:= $(ESC)[A

# Erasing
ERASE_LINE	:= $(ESC)[2K
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

title: ## Print project ascii art in terminal
	@echo "$(PURPLE)$(BOLD)\n$(AUTHOR)'s$(RESET)"
	@echo "$(GREEN)$$TITLE$(RESET)"
	@echo "Executed by $(ITALIC)$(BOLD)$(PURPLE)$(USER)$(RESET) \
		$(CYAN)$(TIME)$(RESET)\n"

.PHONY: title

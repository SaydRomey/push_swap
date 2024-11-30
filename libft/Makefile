# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 21:18:26 by cdumais           #+#    #+#              #
#    Updated: 2024/11/29 21:48:50 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SILENT:
NAME 		:= libft.a
AUTHOR		:= cdumais

INC_DIR		:= inc
SRC_DIR		:= src
OBJ_DIR		:= obj

COMPILE		:= gcc
C_FLAGS		:= -Wall -Wextra -Werror

ARCHIVE		:= ar
AR_FLAGS	:= rcs
AR_INDEX	:= ranlib

REMOVE		:= rm -rf

# **************************************************************************** #
# --------------------------------- H FILES ---------------------------------- #
# **************************************************************************** #
INC	:=			libft
# **************************************************************************** #
# --------------------------------- C FILES ---------------------------------- #
# *********** libc functions ******************* additonal functions ********* #
# **************************************************************************** #
SRC :=			ft_isalpha							ft_substr	  			   \
				ft_isdigit							ft_strjoin				   \
				ft_isalnum							ft_strtrim				   \
				ft_isascii							ft_split				   \
				ft_isprint							ft_itoa					   \
				ft_strlen							ft_strmapi				   \
				ft_memset							ft_striteri				   \
				ft_bzero							ft_putchar_fd			   \
				ft_memcpy							ft_putstr_fd			   \
				ft_memmove							ft_putendl_fd			   \
				ft_strlcpy							ft_putnbr_fd			   \
				ft_strlcat													   \
				ft_toupper													   \
				ft_tolower													   \
				ft_strchr													   \
				ft_strrchr													   \
				ft_strncmp													   \
				ft_memchr													   \
				ft_memcmp													   \
				ft_strnstr													   \
				ft_atoi													   	   \
				ft_calloc													   \
				ft_strdup	
# **************************************************************************** #
# ----------------------------------- BONUS ---------------------------------- #
# ********* linked list functions ******************************************** #
# **************************************************************************** #
SRC +=	 		ft_lstnew													   \
				ft_lstadd_front												   \
				ft_lstsize													   \
				ft_lstlast													   \
				ft_lstadd_back												   \
				ft_lstdelone												   \
				ft_lstclear													   \
				ft_lstiter													   \
				ft_lstmap
# **************************************************************************** #
# ------------------------------- OTHER PROJECTS ----------------------------- #
# ************* get_next_line *********************** ft_printf ************** #
# **************************************************************************** #
SRC +=			get_next_line						ft_printf				   \
													ft_intlen				   \
													ft_putnbr_base_fd
# **************************************************************************** #
# -------------------------------- OTHER UTILS ------------------------------- #
# ************* push_swap **************************************************** #
# **************************************************************************** #
SRC +=			ft_swap
# **************************************************************************** #
# --------------------------------- ALL FILES -------------------------------- #
# **************************************************************************** #
INCS	:=	$(addprefix $(INC_DIR)/, $(addsuffix .h, $(INC)))
SRCS	:=	$(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC)))
OBJS	:=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
# **************************************************************************** #
# -------------------------------- ALL * FILES ------------------------------- #
# **************************************************************************** #
# INCS	:=	$(wildcard $(INC_DIR)/*.h)
# SRCS	:=	$(wildcard $(SRC_DIR)/*.c)
# OBJS	:=	$(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%.o, $(SRCS))
# **************************************************************************** #
# ---------------------------------- RULES ----------------------------------- #
# **************************************************************************** #
all: $(NAME)

$(NAME): $(OBJS)
	@echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)]\\t$(GREEN)created$(RESET)"
	@$(ARCHIVE) $(AR_FLAGS) $(NAME) $(OBJS)
	@$(AR_INDEX) $(NAME)

# $(NAME): $(OBJS)
# 	@echo "$(BOLD)$(PURPLE)$(NAME)$(RESET)$(GREEN) created$(RESET)"
# 	@echo "$(GREEN)$$TITLE$(RESET)"
# 	@echo "Executed by $(ITALIC)$(BOLD)$(PURPLE)$(USER)$(RESET) \
# 		$(CYAN)$(TIME)$(RESET)\n"
# 	@$(ARCHIVE) $(AR_FLAGS) $(NAME) $(OBJS)
# 	@$(AR_INDEX) $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCS) | $(OBJ_DIR)
	@echo "$(CYAN)Compiling...$(ORANGE)\t$(notdir $<)$(RESET)"
	@$(COMPILE) $(C_FLAGS) -I$(INC_DIR) -o $@ -c $<
	@printf "$(UP)$(ERASE_LINE)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@if [ -n "$(wildcard $(OBJ_DIR))" ]; then \
		$(REMOVE) $(OBJ_DIR); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Object files removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No object files to remove$(RESET)"; \
	fi

fclean: clean
	@if [ -n "$(wildcard $(NAME))" ]; then \
		$(REMOVE) $(NAME); \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(GREEN)Library removed$(RESET)"; \
	else \
		echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)] \
		$(YELLOW)No library to remove$(RESET)"; \
	fi

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
# -------------------------------- NORMINETTE -------------------------------- #
# **************************************************************************** #
norm:
	@echo "$(BOLD)$(YELLOW)Norminetting $(PURPLE)$(NAME)$(RESET)"
	@norminette -o $(INCS)
	@norminette -o $(SRCS)

nm:
	@echo "$(BOLD)$(YELLOW)Functions in $(PURPLE)$(UNDERLINE)$(NAME)$(RESET):"
	@nm $(NAME) | grep U | grep -v 'ft_' \
				| sed 's/U//g' | sed 's/__//g' | sed 's/ //g' \
				| sort | uniq

.PHONY: norm nm
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

██      ██ ██████  ███████ ████████ 
██      ██ ██   ██ ██         ██    
██      ██ ██████  █████      ██    
██      ██ ██   ██ ██         ██    
███████ ██ ██████  ██         ██   

endef
export TITLE

USER		:=$(shell whoami)
TIME		:=$(shell date "+%H:%M:%S")

title:
	@echo "[$(BOLD)$(PURPLE)$(NAME)$(RESET)]\\t$(GREEN)created$(RESET)"
	@echo "$(GREEN)$$TITLE$(RESET)"
	@echo "Executed by $(ITALIC)$(BOLD)$(PURPLE)$(USER)$(RESET) \
		$(CYAN)$(TIME)$(RESET)\n"

.PHONY: title

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 21:18:26 by cdumais           #+#    #+#              #
#    Updated: 2023/06/19 17:30:12 by cdumais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# .SILENT:

NAME		:=	libft.a

CC			:=	gcc
CF			:=	-Wall -Werror -Wextra
CI			:=	-I-I$(INC)
LIBC		:=	ar -rcs

REMOVE		:=	rm -f
REMDIR		:=	rm -rf

INC			:=	inc/
SRC			:=	src/
OBJ			:=	obj/

# **************************************************************************** #
C_SRC	=																	   \
ft_isalnum.c	ft_memchr.c		ft_strlen.c		ft_substr.c		ft_atoi.c	   \
ft_isalpha.c	ft_memcmp.c		ft_strlcat.c	ft_strdup.c		ft_itoa.c	   \
ft_isascii.c	ft_memcpy.c		ft_strlcpy.c	ft_strjoin.c				   \
ft_isdigit.c	ft_memmove.c	ft_strchr.c		ft_strtrim.c	ft_putchar_fd.c\
ft_isprint.c	ft_memset.c		ft_strrchr.c	ft_striteri.c	ft_putstr_fd.c \
ft_tolower.c	ft_bzero.c		ft_strncmp.c	ft_strmapi.c	ft_putendl_fd.c\
ft_toupper.c	ft_calloc.c		ft_strnstr.c	ft_split.c		ft_putnbr_fd.c 
# **************************************************************************** #
SRCS		:= $(addprefix $(SRC), $(C_SRC))
OBJS		:= $(addprefix $(OBJ), $(C_SRC:.c=.o))
# **************************************************************************** #
C_BONUS	=																	   \
ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstmap.c		ft_lstlast.c   \
			ft_lstadd_back.c	ft_lstclear.c	ft_lstiter.c				   \
								ft_lstdelone.c								   
# **************************************************************************** #				
BSRCS		:= $(addprefix $(SRC), $(C_BONUS))
BOBJS		:= $(addprefix $(OBJ), $(C_BONUS:.c=.o))
# **************************************************************************** #
GNL =																		   \
get_next_line.c																   
# **************************************************************************** #
GSRCS		:= $(addprefix $(SRC), $(GNL))
GOBJS		:= $(addprefix $(OBJ), $(GNL:.c=.o))
# **************************************************************************** #
PRINTF =																	   \
ft_printf.c		ft_intlen.c		ft_putnbr_base_fd.c								
# **************************************************************************** #
PFSRCS		:= $(addprefix $(SRC), $(PRINTF))
PFOBJS		:= $(addprefix $(OBJ), $(PRINTF:.c=.o))
# **************************************************************************** #
PUSHWAP =																	   \
ft_swap.c
# **************************************************************************** #
PWSRCS		:= $(addprefix $(SRC), $(PUSHWAP))
PWOBJS		:= $(addprefix $(OBJ), $(PUSHWAP:.c=.o))
# **************************************************************************** #
# all: $(NAME)
# 	@echo "$(GREEN)$$TITLE$(RESET)"
# 	@echo "Executed by $(ITALIC)$(BOLD)$(PURPLE)$(USER)$(RESET) \
# 		$(CYAN)$(TIME)$(RESET)\n"

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS) $(BOBJS) $(GOBJS) $(PFOBJS) $(PWOBJS)
	@$(LIBC) $(NAME) $(OBJS) $(BOBJS) $(GOBJS) $(PFOBJS) $(PWOBJS)
	@echo "$(BOLD)$(PURPLE)$(NAME)$(GREEN) created$(RESET)"


$(OBJ)%.o: $(SRC)%.c
	@echo "$(BLUE)$(BOLD)Compiling $(RESET)$(CYAN)$(notdir $<)$(RESET)"
	@mkdir -p $(OBJ)
	@$(CC) $(CF) $(CI) -c $< -o $@
	@printf $(UP)$(CUT)

clean:
	@if [ -n "$(wildcard $(OBJ)*.o)" ]; then \
		$(REMOVE) $(OBJS) $(BOBJS) $(GOBJS) $(PFOBJS) $(PWOBJS) ; \
		$(REMDIR) $(OBJ); \
		echo "$(GREEN)Object files removed$(RESET)"; \
	else \
		echo "$(YELLOW)No object files to remove$(RESET)"; \
	fi

fclean: clean
	@if [ -n "$(wildcard $(NAME))" ]; then \
		$(REMOVE) $(NAME); \
		echo "$(BOLD)$(PURPLE)$(NAME)$(GREEN) removed$(RESET)"; \
	else \
		echo "$(YELLOW)No library to remove$(RESET)"; \
	fi

vclean:	fclean
	$(eval NOMISC :=$(filter-out Makefile inc src, $(wildcard *)))
	@if [ -n "$(NOMISC)" ]; then \
		$(REMOVE) $(NOMISC); \
		echo "$(GREEN)Cleaned up: $(RESET) $(NOMISC)"; \
	else \
		echo "$(YELLOW)All cleaned up !$(RESET)"; \
	fi;

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader src/*.c
	norminette -R CheckDefine inc/*.h

.PHONY:	all clean fclean re \
		bonus norm vclean
# **************************************************************************** #
# Colors
BLACK		=\033[30m
RED			=\033[31m
GREEN		=\033[32m
YELLOW		=\033[33m
BLUE		=\033[34m
PURPLE		=\033[35m
CYAN		=\033[36m
WHITE		=\033[37m

# # Text
ERASE		=\033[2K\r
RESET		=\033[0m
BOLD		=\033[1m
FAINT		=\033[2m
ITALIC		=\033[3m
UNDERLINE	=\033[4m
# BLINK		=\033[5m #no effect on iterm?
INVERT		=\033[7m
STRIKE		=\033[9m

# # Background
BG_BLACK	=\033[40m
BG_RED		=\033[41m
BG_GREEN	=\033[42m
BG_YELLOW	=\033[43m
BG_BLUE		=\033[44m
BG_PURPLE	=\033[45m
BG_CYAN		=\033[46m
BG_WHITE	=\033[47m

# # ? (with printf)
UP			="\033[A"
CUT			="\033[K"

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

USER	=$(shell whoami)
TIME	=$(shell date "+%H:%M:%S")

# **************************************************************************** #
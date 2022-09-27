# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 14:51:29 by mweverli      #+#    #+#                  #
#    Updated: 2022/08/25 10:43:47 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#========================================#
#========== GENERAL VARIABLES ===========#
#========================================#

NAME		:=	printf.a
NAME_BASE	:=	$(basename $(NAME))
SRC_DIR		:=	./src
OBJ_DIR		:=	./obj
INC_DIR		:=	./include

#=========  SOURCE  VARIABLES:  =========#

SRC			:=	ft_printf.c \
				ft_printf_dec.c \
				ft_printf_hex.c \
				ft_printf_mis.c \
				ft_printf_str.c \
				ft_printf_utils.c 

OBJ			:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
HEADER		:=	-I $(INC_DIR)

#========================================#
#=========      UTENSILS:       =========#
#========================================#

ifdef DEBUG
CFL			:=	-Wall -Werror -Wextra -g
else
CFL			:=	-Wall -Werror -Wextra
endif

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^
	@echo "$(GREEN)$(BOLD)========= $(NAME) COMPILED ========$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFL) -c $< -o $@ $(HEADER)
	@echo "$(GREEN)$(BOLD)COMPILING: $(notdir $<)$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)========= $(NAME) COMPILED ========$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

#========================================#
#=========    MISCELLANEOUS:    =========#
#========================================#

.PHONY: all lean fclean re db

.DEFAULT_GOAL := all

BOLD	:= \033[1m
GREEN	:= \033[32;1m
RED		:= \033[31;1m
RESET	:= \033[0m

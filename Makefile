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

NAME	:=	printf.a
SRC_DIR	:=	./src
OBJ_DIR	:=	./OBJ
INC_DIR	:=	./include

SRC		:=	$(shell ls src/)
OBJ		:=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
HEADER	:=	-I $(INC_DIR)

ifdef DB
CFL		:=	-Wall -Werror -Wextra -g
else
CFL		:=	-Wall -Werror -Wextra
endif

#============== COLOURS  ===============#

BOLD	:= \033[1m
GREEN	:= \033[32;1m
RED		:= \033[31;1m
RESET	:= \033[0m

#========================================#
#============== RECIPIES  ===============#
#========================================#

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^
	@echo "$(GREEN)$(BOLD)FINISHED COMPILING: $(NAME)$(RESET)"

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFL) -c $< -o $@ $(HEADER)
	@echo "$(GREEN)$(BOLD)COMPILING: $(notdir $<)$(RESET)"


db: clean
	@$(MAKE) test DB=1

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(BOLD)Cleaning Prinf$(RESET)"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all lean fclean re db

.DEFAULT_GOAL := all

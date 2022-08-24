# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 14:51:29 by mweverli      #+#    #+#                  #
#    Updated: 2022/08/24 22:49:23 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Remove all debugging functionalities before hand-in.

#STANDARD VARIABLES:

NAME	:=	printf
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

# Recipes:

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME).a $^

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFL) -c $< -o $@ $(HEADER)

db: clean
	@$(MAKE) test DB=1

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME).a

re: fclean all

.PHONY: clean fclean tclean re db

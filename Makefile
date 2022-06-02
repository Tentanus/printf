# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 14:51:29 by mweverli      #+#    #+#                  #
#    Updated: 2022/06/02 17:55:46 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Remove all debugging functionalities before hand-in.

#STANDARD VARIABLES

NAME	=	ft_printf
EXE 	=	$(NAME).out
OBJ_DIR	=	./OBJ


#OBJ		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

SRC		=	\


ifdef DB
CFL		=	-Wall -Werror -Wextra -g
else
CFL		=	-Wall -Werror -Wextra
endif


# Recipes:

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $< 

test: $(OBJ)
	$(CC) $(CFL) -c main.c -o ./OBJ/main.o
	$(CC) $(CFL) -o $(EXE) $^

db: clean
	@ $(MAKE) test DB=1
	./$(EXE)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFL) -c $< -o $@


clean:
	@mkdir -p $(OBJ_DIR)
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(EXE)

re: fclean all

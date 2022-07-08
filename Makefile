# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <mweverli@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 14:51:29 by mweverli      #+#    #+#                  #
#    Updated: 2022/07/08 22:30:57 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#Remove all debugging functionalities before hand-in.

#VARIABLES:

NAME	=	libftprintf
EXE 	=	$(NAME).out
OBJ_DIR	=	./OBJ

OBJ		=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

SRC		=	ft_printf.c\
			ft_printf_dec.c\
			ft_printf_hex.c\
			ft_printf_str.c\
			ft_printf_mis.c\
			ft_printf_utils_01.c\

ifdef DB
CFL		=	-Wall -Werror -Wextra -g
else
CFL		=	-Wall -Werror -Wextra
endif

#RECIPES MAKEFILE:

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME).a $^ 

test: $(OBJ)
	$(CC) $(CFL) -o $(OBJ_DIR)/main.o -c main.c 
	$(CC) $(CFL) -o $(EXE) $^ $(OBJ_DIR)/main.o
	./$(EXE)

db: clean
	@ $(MAKE) test DB=1

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFL) -c $< -o $@

clean:
	@mkdir -p $(OBJ_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME).a

tclean: clean fclean
	rm -f $(EXE)

re: fclean all

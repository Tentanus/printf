# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mweverli <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/29 14:51:29 by mweverli      #+#    #+#                  #
#    Updated: 2021/12/02 19:35:09 by mweverli      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

#VAR

CC = gcc
CFL = -Wall -Werror -Wextra
NAME = libftprintf.a

LIB_LIS =	\

LIB_DIR =./LIBFT
LIB_SRC =$(addprefix $(LIB_DIR)/,$(LIB_LIS))
LIB_OBJ =$(addprefix $(OBJ_DIR)/,$(LIB_SRC:.c=.o))

SRC =	\

OBJ_DIR =./OBJ
OBJ =$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# Recipes:

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	ar rcs $(NAME) $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFL) -c $< -o $@

$(LIB_OBJ)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFL) -c $< -o $@

clean:
	@mkdir -p $(OBJ_DIR)
	rm -r $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

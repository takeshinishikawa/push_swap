# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:21:36 by rtakeshi          #+#    #+#              #
#    Updated: 2022/03/16 18:42:44 by rtakeshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror -g -ggdb3
RM			=	rm -rf
OBJ_DIR		=	obj

INC			=	./inc/push_swap.h
SRC_DIR		=	src
SRC			=	$(addprefix $(SRC_DIR)/, push_swap.c check_number.c \
				validations.c init_data.c)

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:			$(NAME)

$(NAME):		$(OBJ_DIR) $(OBJ) $(INC)
				make -C libft/
				gcc $(CFLAGS) $(OBJ) $(INC) libft/libft.a -o $(NAME)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(INC)
				gcc $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
				mkdir $(OBJ_DIR)

clean:
				$(RM) $(OBJ_DIR)
				make clean -C libft/

fclean: 		clean
				$(RM) $(NAME)
				make fclean -C libft/

re:				fclean all

.PHONY:			all clean fclean re

runleak:	all
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

runleakbonus:	bonus
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BONUS)

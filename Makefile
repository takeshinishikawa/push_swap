# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 13:21:36 by rtakeshi          #+#    #+#              #
#    Updated: 2022/03/19 21:12:22 by rtakeshi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CFLAGS		=	-Wall -Wextra -Werror -g -ggdb3
RM			=	rm -rf
OBJ_DIR		=	obj

INC			=	./inc/push_swap.h
SRC_DIR		=	src
SRC			=	$(addprefix $(SRC_DIR)/, push_swap.c check_number.c \
				validations.c init_data1.c init_data2.c \
				swap.c push.c rotate.c rev_rotate.c sort.c)

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

runleak_valid:	all
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 5 6 8 4 1 2 3 0 9 7

runleak_invalid:	all
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 5 6 8 4 1 2 3 0 9 5

runleak_invalid_text:	all
	valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) 5 6 8 4 1 2 3 0 9 five

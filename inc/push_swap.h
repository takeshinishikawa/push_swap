/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:41:46 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/16 18:42:25 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <stdlib.h>
# include "../libft/libft.h"


typedef struct		s_node
{
	int				nbr;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}					t_node;

typedef struct	s_sentinel
{
	int		total; //OK
	int		size_a; //OK
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*small_a;
	t_node	*big_a;
	int		size_b; //OK
	t_node	*head_b;
	t_node	*tail_b;
	t_node	*small_b;
	t_node	*big_b;
}				t_sentinel;


int	check_number(const char *str);
int	check_argc(int argc);
int	check_argv(char	*argv);
void	init_data(t_sentinel **data, int argc);


#endif

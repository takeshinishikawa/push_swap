/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:41:46 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 21:14:50 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	struct s_node	*previous;
	struct s_node	*next;
}					t_node;

typedef struct s_sentinel
{
	int		total;
	int		size_a;
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*small_a;
	t_node	*big_a;
	int		size_b;
	t_node	*head_b;
	t_node	*tail_b;
	t_node	*small_b;
	t_node	*big_b;
}				t_sentinel;

int		check_number(const char *str);
int		check_argc(int argc);
int		check_argv(char	*argv);
int		is_sorted(t_sentinel *data);
int		is_repeated(t_sentinel *data);
void	init_data(t_sentinel *data, int argc);
int		create_node(t_node **new_node, t_sentinel *data, long int aux);
int		add_to_stack(t_sentinel *data, long int aux);
void	normalize(t_sentinel *data);
int		get_numbers(t_sentinel *data, char *argv[]);
void	get_small_and_big_a(t_sentinel *data);
void	get_small_and_big_b(t_sentinel *data);
void	swap_a(t_sentinel *data, char *cmd);
void	swap_b(t_sentinel *data, char *cmd);
void	swap_s(t_sentinel *data);
void	push_a(t_sentinel *data);
void	push_b(t_sentinel *data);
void	rotate_a(t_sentinel *data, char *cmd);
void	rotate_b(t_sentinel *data, char *cmd);
void	rotate_r(t_sentinel *data);
void	rev_rotate_a(t_sentinel *data, char *cmd);
void	rev_rotate_b(t_sentinel *data, char *cmd);
void	rev_rotate_r(t_sentinel *data);
void	print_and_get(char *cmd, t_sentinel *data);
void	three_elements(t_sentinel *data);
void	five_elements(t_sentinel *data);
void	radix_sort(t_sentinel *data);
int		sort_stack(t_sentinel *data);

#endif

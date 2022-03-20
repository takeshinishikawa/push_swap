/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:30:55 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 15:31:13 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rev_rotate_a(t_sentinel *data, char *cmd)
{
	t_node	*new_head;
	t_node	*new_tail;

	new_head = data->tail_a;
	new_tail = data->tail_a->previous;
	data->head_a = new_head;
	data->tail_a = new_tail;
	if (!ft_strncmp(cmd, "rra", 3))
	{
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rev_rotate_b(t_sentinel *data, char *cmd)
{
	t_node	*new_head;
	t_node	*new_tail;

	new_head = data->tail_b;
	new_tail = data->tail_b->previous;
	data->head_b = new_head;
	data->tail_b = new_tail;
	if (!ft_strncmp(cmd, "rrb", 3))
	{
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rev_rotate_r(t_sentinel *data)
{
	ft_putstr_fd("rrr", 1);
	ft_putstr_fd("\n", 1);
	rev_rotate_a(data, "");
	rev_rotate_b(data, "");
}

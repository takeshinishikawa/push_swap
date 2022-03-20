/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:27:04 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 15:28:12 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_a(t_sentinel *data, char *cmd)
{
	t_node	*new_head;

	new_head = data->head_a->next;
	new_head->previous = data->head_a->previous;
	data->tail_a->next = new_head;
	data->head_a->next = new_head->next;
	new_head->next->previous = data->head_a;
	new_head->next = data->head_a;
	data->head_a->previous = new_head;
	data->head_a = new_head;
	data->tail_a = data->head_a->previous;
	if (!ft_strncmp(cmd, "sa", 2))
	{
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	swap_b(t_sentinel *data, char *cmd)
{
	t_node	*new_head;

	new_head = data->head_b->next;
	new_head->previous = data->head_b->previous;
	data->tail_b->next = new_head;
	data->head_b->next = new_head->next;
	new_head->next->previous = data->head_b;
	new_head->next = data->head_b;
	data->head_b->previous = new_head;
	data->head_b = new_head;
	data->tail_b = data->head_b->previous;
	if (!ft_strncmp(cmd, "sb", 2))
	{
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	swap_s(t_sentinel *data)
{
	ft_putstr_fd("ss", 1);
	ft_putstr_fd("\n", 1);
	swap_a(data, "");
	swap_b(data, "");
}

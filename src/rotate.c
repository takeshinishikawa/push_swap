/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:29:44 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 15:30:03 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_a(t_sentinel *data, char *cmd)
{
	data->tail_a = data->head_a;
	data->head_a = data->head_a->next;
	if (!ft_strncmp(cmd, "ra", 2))
	{
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rotate_b(t_sentinel *data, char *cmd)
{
	data->tail_b = data->head_b;
	data->head_b = data->head_b->next;
	if (!ft_strncmp(cmd, "rb", 2))
	{
		ft_putstr_fd(cmd, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rotate_r(t_sentinel *data)
{
	ft_putstr_fd("rr", 1);
	ft_putstr_fd("\n", 1);
	rotate_a(data, "");
	rotate_b(data, "");
}

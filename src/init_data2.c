/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:31:04 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 20:00:50 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	get_small(t_node **head, t_node **small, int size)
{
	int		i;
	t_node	*aux;

	i = 0;
	aux = *head;
	*small = aux;
	while (i < size)
	{
		if ((*small)->index > aux->index)
			(*small) = aux;
		aux = aux->next;
		i++;
	}
}

void	get_big(t_node **head, t_node **big, int size)
{
	int		i;
	t_node	*aux;

	i = 0;
	aux = *head;
	*big = aux;
	while (i < size)
	{
		if ((*big)->index > aux->index)
			(*big) = aux;
		aux = aux->next;
		i++;
	}
}

void	get_small_and_big_a(t_sentinel *data)
{
	if (data->size_a >= 1)
	{
		get_small(&data->head_a, &data->small_a, data->size_a);
		get_big(&data->head_a, &data->big_a, data->size_a);
	}
}

void	get_small_and_big_b(t_sentinel *data)
{
	if (data->size_b >= 1)
	{
		get_small(&data->head_b, &data->small_b, data->size_b);
		get_big(&data->head_b, &data->big_b, data->size_b);
	}
}

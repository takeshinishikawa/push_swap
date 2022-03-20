/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:28:41 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 15:28:52 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_a(t_sentinel *data)
{
	t_node	*node;

	node = data->head_b;
	data->head_b = data->head_b->next;
	data->head_b->previous = node->previous;
	data->tail_b->next = data->head_b;
	node->previous = NULL;
	node->next = NULL;
	data->size_b -= 1;
	data->size_a += 1;
	if (data->size_a != 1)
	{
		node->next = data->head_a;
		node->previous = data->head_a->previous;
		data->head_a->previous = node;
		data->tail_a->next = node;
	}
	else
	{
		node->previous = node;
		node->next = node;
		data->tail_a = node;
	}
	data->head_a = node;
	print_and_get("pa", data);
}

void	push_b(t_sentinel *data)
{
	t_node	*node;

	node = data->head_a;
	data->head_a = data->head_a->next;
	data->head_a->previous = node->previous;
	data->tail_a->next = data->head_a;
	node->previous = NULL;
	node->next = NULL;
	data->size_a -= 1;
	data->size_b += 1;
	if (data->size_b != 1)
	{
		node->next = data->head_b;
		node->previous = data->head_b->previous;
		data->head_b->previous = node;
		data->tail_b->next = node;
	}
	else
	{
		node->previous = node;
		node->next = node;
		data->tail_b = node;
	}
	data->head_b = node;
	print_and_get("pb", data);
}

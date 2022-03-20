/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:52:42 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 21:14:54 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	three_elements(t_sentinel *data)
{
	if (!is_sorted(data))
		return ;
	if (data->head_a->index > data->head_a->next->index && \
	data->head_a->index < data->tail_a->index)
		swap_a(data, "sa");
	else if (data->head_a->index > data->head_a->next->index && \
	data->head_a->next->index > data->tail_a->index)
	{
		swap_a(data, "sa");
		rev_rotate_a(data, "rra");
	}
	else if (data->head_a->index > data->head_a->next->index && \
	data->head_a->next->index < data->tail_a->index)
		rotate_a(data, "ra");
	else if (data->head_a->index < data->head_a->next->index && \
	data->head_a->index < data->tail_a->index)
	{
		swap_a(data, "sa");
		rotate_a(data, "ra");
	}
	else if (data->head_a->index < data->head_a->next->index && \
	data->head_a->next->index > data->tail_a->index)
		rev_rotate_a(data, "rra");
}

void	five_elements(t_sentinel *data)
{
	while (data->size_a != 3)
	{
		if (data->head_a->index == 0 || data->head_a->index == 4)
			push_b(data);
		else if (data->head_a->next->index == 0 || \
		data->head_a->next->index == 4)
			swap_a(data, "sa");
		else if (data->tail_a->index == 0 || data->tail_a->index == 4)
			rev_rotate_a(data, "rra");
		else
			rotate_a(data, "ra");
	}
	three_elements(data);
	while (data->size_a != 5)
	{
		if (data->head_b->index < data->tail_b->index)
			swap_b(data, "sb");
		push_a(data);
		if (data->head_a->index > data->head_a->next->index)
			rotate_a(data, "ra");
	}
}

void	radix_sort(t_sentinel *data)
{
	int	i;
	int	j;
	int	aux;

	i = 0;
	while (is_sorted(data))
	{
		j = 0;
		while (j < data->total)
		{
			aux = data->head_a->index;
			if ((aux >> i) & 1)
				rotate_a(data, "ra");
			else
				push_b(data);
			j++;
		}
		while (data->size_b)
			push_a(data);
		i++;
	}
}

int	sort_stack(t_sentinel *data)
{
	if (data->total == 2)
		swap_a(data, "sa");
	else if (data->total == 3)
		three_elements(data);
	else if (data->total == 5)
		five_elements(data);
	else
		radix_sort(data);
	return (0);
}

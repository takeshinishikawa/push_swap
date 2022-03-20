/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:31:04 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/19 15:24:56 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_data(t_sentinel *data, int argc)
{
	data->total = argc - 1;
	data->size_a = 0;
	data->size_b = 0;
	data->head_a = NULL;
	data->tail_a = NULL;
	data->head_b = NULL;
	data->tail_b = NULL;
}

int	create_node(t_node **new_node, t_sentinel *data, long int aux)
{
	*new_node = malloc(sizeof(t_node));
	if (*new_node == NULL)
		return (1);
	(*new_node)->index = data->total;
	(*new_node)->nbr = (int)aux;
	(*new_node)->next = NULL;
	data->size_a++;
	return (0);
}

int	add_to_stack(t_sentinel *data, long int aux)
{
	t_node	*new_node;

	new_node = NULL;
	if (create_node(&new_node, data, aux))
		return (1);
	if (data->size_a == 1)
	{
		data->head_a = new_node;
		data->tail_a = data->head_a;
		data->small_a = data->head_a;
		data->big_a = data->head_a;
		new_node->previous = NULL;
	}
	else
	{
		new_node->previous = data->tail_a;
		data->tail_a->next = new_node;
		data->tail_a = data->tail_a->next;
		if (data->size_a == data->total)
		{
			new_node->next = data->head_a;
			data->head_a->previous = new_node;
		}
	}
	return (0);
}

void	normalize(t_sentinel *data)
{
	int		i;
	t_node	*curr;
	t_node	*needle;

	i = 0;
	while (i < data->total)
	{
		curr = data->head_a;
		while (curr->index != data->total)
			curr = curr->next;
		needle = curr->next;
		while (needle != curr)
		{
			if (needle->index == data->total && needle->nbr < curr->nbr)
				curr = needle;
			needle = needle->next;
		}
		curr->index = i;
		i++;
	}
	get_small_and_big_a(data);
}

int	get_numbers(t_sentinel *data, char *argv[])
{
	int			i;
	long int	aux;

	i = 1;
	while (argv[i])
	{
		if (!check_argv(argv[i]))
			return (1);
		if (!check_number(argv[i]))
			return (1);
		aux = ft_atoi(argv[i]);
		if (add_to_stack(data, aux))
			return (1);
		i++;
	}
	if (is_repeated(data))
		return (1);
	normalize(data);
	return (0);
}

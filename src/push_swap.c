/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:44:10 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/20 13:28:15 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_and_get(char *cmd, t_sentinel *data)
{
	ft_putstr_fd(cmd, 1);
	ft_putstr_fd("\n", 1);
	if (strncmp(cmd, "pa", 2))
		get_small_and_big_a(data);
	else if (strncmp(cmd, "pb", 2))
		get_small_and_big_b(data);
	if (!data->size_a)
	{
		data->head_a = NULL;
		data->tail_a = NULL;
	}
	else if (!data->size_b)
	{
		data->head_b = NULL;
		data->tail_b = NULL;
	}
}

void	free_nodes(t_sentinel *data)
{
	t_node	*aux;

	while (data->size_a)
	{
		aux = data->head_a;
		data->head_a = data->head_a->next;
		free(aux);
		data->size_a--;
	}
	while (data->size_b)
	{
		aux = data->head_b;
		data->head_b = data->head_b->next;
		free(aux);
		data->size_b--;
	}
}

int	main(int argc, char *argv[])
{
	t_sentinel	data;

	if (check_argc(argc))
		return (1);
	init_data(&data, argc);
	if (get_numbers(&data, argv))
	{
		ft_putstr_fd("Error\n", 1);
		free_nodes(&data);
		return (1);
	}
	if (!is_sorted(&data))
	{
		free_nodes(&data);
		return (1);
	}
	if (sort_stack(&data))
	{
		free_nodes(&data);
		return (1);
	}
	free_nodes(&data);
	return (0);
}

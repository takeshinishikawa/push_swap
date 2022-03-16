/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtakeshi <rtakeshi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:44:10 by rtakeshi          #+#    #+#             */
/*   Updated: 2022/03/16 19:04:00 by rtakeshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		create_node(t_node **new_node, t_sentinel *data, long int aux)
{
	*new_node = malloc(sizeof(t_node));
	if (*new_node == NULL)
		return (1);
	(*new_node)->index = 0;
	(*new_node)->nbr = (int)aux;
	(*new_node)->next = NULL;
	data->size_a++;
	return (0);
}

int		add_to_stack(t_sentinel *data, long int aux)
{
	t_node	*new_node;

	new_node = NULL;
	if (create_node(&new_node, data, aux))
		return (1);
	/*new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return (1);
	new_node->index = 0;
	new_node->nbr = (int)aux;
	new_node->next = NULL;
	data->size_a++;*/
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
	}
	return (0);
}

int		get_numbers(t_sentinel *data, char *argv[])
{
	int			i;
	long int	aux;

	i = 1;
	while (i <= data->total)
	{
		printf("%s\n", argv[i]);
		i++;
	}
	printf("--------------------------\n");
	i = 1;
	while (i <= data->total)
	{
		printf("i is %d\n", i);
		printf("argv[i] is '%s'\n", argv[i]);
		if (!check_argv(argv[i]))
			return (1);
		if (!check_number(argv[i]))
			return (1);
		aux = ft_atoi(argv[i]);
		printf("aux is %ld\n\n", aux);
		/*if (add_to_stack(data, aux))
			return (1);
		printf("number in linked-list is %d\n", data->head_a->nbr);*/
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_sentinel	*data;

	if (check_argc(argc))
		return (1);
	init_data(&data, argc);
	//get_number -> inicializa a stack_a alimentando c os valores,
	//checar todos os mallocs, verifica se todos os argvs são números,
	//verifica se estão entre/igual INT_MIN e INT_MAX
	get_numbers(data, argv);

	/*while (data->head_a)
	{
		printf("size_a %d\n", data->head_a->nbr);
		data->head_a = data->head_a->next;
	}*/


	//validate_number -> valida se existem números repetidos

	//is_sorted -> checks if it`s already sorted
	//(returns if any number is smaller than the one comparing)

	//normalize numbers

	//ordenate with some algorithm

	//free_nodes -> clear all nodes in stack_a and stack_b IF there is any node
	return (0);
}

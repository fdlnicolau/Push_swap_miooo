/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:55:02 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/06 23:41:13 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	put_index(t_stack *stack_a)
{
	int			size;
	int			i;
	t_stack 	*aux;
	long		min;
	long		last;

	i = 1;
	last = MIN_INT - 1;
	size = stack_size(stack_a);
	while(i <= size)
	{
		min = MAX_INT;
		aux = stack_a;
		while(aux)
		{
			
			if(aux->value < min && aux->value > last)
				min = aux->value;
			aux = aux->next;
		}
		unsigned_index(stack_a, min, i);
		last = min;
		i++;
	}
}

void unsigned_index(t_stack *stack_a, long min, int index)
{
	t_stack *aux;
	aux = stack_a;
	while (aux)
	{
		if (aux->value == min)
		{
			aux->index = index;
			write(1, "index:", 6);
			printf("%ld\n", min);
		}
		aux = aux->next;
	}
}
t_stack *max_index(t_stack **stack_a)
{
	t_stack *copy;
	t_stack	*max_index;
	
	copy = *stack_a;
	max_index = *stack_a;

	while(copy)
	{
		if(copy->value > max_index->value)
			max_index = copy;
		copy = copy->next;
	}
	return(max_index);
	
}
t_stack *min_index(t_stack **stack_a)
{
	t_stack *copy;
	t_stack	*min_index;
	
	copy = *stack_a;
	min_index = *stack_a;

	while(copy)
	{
		if(copy->value < min_index->value)
			min_index = copy;
		copy = copy->next;
	}
	return(min_index);
	
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:55:02 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 10:55:25 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	put_index(t_stack *stack_a)
{
	int			size;
	int			i;
	long		min;
	long		last;

	i = 1;
	last = MIN_INT - 1;
	size = stack_size(stack_a);
	while (i <= size) 
	{
		min = min_index(stack_a, last); // Encontrar el mínimo mayor que last 
			unsigned_index(stack_a, min, i); // Asignar el índice al nodo con el valor mínimo
			last = min; // Actualizar last al valor mínimo encontrado	
		i++;
	}
}

void unsigned_index(t_stack *stack_a, long value, int index)
{
	t_stack *current;
	current = stack_a;
	// char *str = ft_itoa(index);
	while (current)
	{
		if (current->value == value)
		{
			// printf("\n");
			current->index = index;
			// write(1, "index:", 6);
			// write(1, str, ft_strlen(str));
			// str = ft_itoa((int)min);
			// write(1, "Value:", 6);
			// write(1, str, ft_strlen(str));
		}
		current = current->next;
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
long min_index(t_stack *stack_a, long last)
{
	t_stack *current;
	long min;
	
	min = MAX_INT;
	current = stack_a;
	while(current != NULL)
	{
		if(current->value < min && current->value > last)
			min = current->value;
		current = current->next;
	}
	return(min);
}
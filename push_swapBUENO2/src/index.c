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

void	put_index(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*biggest;
	int		value;

	while (--size > 0)
	{
		ptr = stack_a;
		biggest = NULL;
		value = INT_MIN;
		while (ptr)
		{
			if (ptr->value >= value && ptr->index == 0)
			{
				value = ptr->value;
				biggest = ptr;
				ptr = ptr->next;
			}
			else
				ptr = ptr->next;
		}
		if (biggest != NULL)
			biggest->index = size;
	}
}

void unsigned_index(t_stack *stack_a, long value, int index)
{
	t_stack *current;
	current = stack_a;

	while (current)
	{
		if (current->value == value)
		{
			current->index = index;
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
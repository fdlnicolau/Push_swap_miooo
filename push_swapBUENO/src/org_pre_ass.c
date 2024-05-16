/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   org_pre_ass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:36 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 15:45:09 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void preparation_of_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int i;

	size = stack_size(*stack_a);
	i = 0;
	while(i < size / 2 && stack_size(*stack_a) > 3)
	{
		if((*stack_a)->index <= (size / 2))
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
	size = stack_size(*stack_a);
	while(size > 3)
	{
		push_b(stack_a, stack_b, 1);
		size--;
	}
}

 void organize_three (t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

	first = *stack_a;
	second = first->next;
	third = second->next;

	if (first->value > second->value && first->value > third->value) 
	{
		rotate_a(stack_a, 1);
		organize_three(stack_a);
	}
	else if (first->value < second->value && second->value > third->value) 
	{
		reverse_rotate_a(stack_a, 1);
		organize_three(stack_a);
	}
	else if (first->value > second->value && first->value < third->value) 
		swap_a(stack_a, 1);	
}



void	last_step(t_stack **stack_a)
{
	int	lowest_position;
	int	size;

	size = stack_size(*stack_a);
	lowest_position = glowest_i_p(stack_a);
	if (lowest_position > size / 2)
	{
		while (lowest_position < size)
		{
			reverse_rotate_a(stack_a, 1);
			lowest_position++;
		}
	}
	else
	{
		while (lowest_position > 0)
		{
			rotate_a(stack_a, 1);
			lowest_position--;
		}
	}
}

int	glowest_i_p(t_stack **stack_a)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_post;

	tmp = *stack_a;
	lowest_index = INT_MAX;
	assign_position(stack_a);
	lowest_post = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_post = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_post);
}
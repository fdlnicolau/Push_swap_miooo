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

/* void preparation_of_numbers(t_stack **stack_a, t_stack **stack_b)
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
} */

 void organize_three (t_stack **stack_a)
{
	int first;
	int second;
	int third;

	first = node_at(*stack_a, 0)->value;
	second = node_at(*stack_a, 1)->value;
	third = node_at(*stack_a, 2)->value;

	if (first > second && third > second && third > first)
		swap_a(stack_a, 1);
	else if(first > second && third > second && first > third)	
		rotate_a(stack_a, 1);
	else if (second > first && second > third && first > third) 
		reverse_rotate_a(stack_a, 1);
	else if (second > first && second > third && third > first) 
	{
		swap_a(stack_a, 1);
		rotate_a(stack_a, 1);
	}
	else if(first > second && second > third && first > third)
	{
		swap_a(stack_a, 1);
		reverse_rotate_a(stack_a, 1);
	}
}

void	last_step(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_size(*stack_b))
		push_a(stack_b, stack_a, 1);
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
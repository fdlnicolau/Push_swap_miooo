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
	while(size > 6 && i < size / 2)
	{
		if((*stack_a)->index <= size / 2)
		{
			push_b(stack_a, stack_b, 1);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
	while(size - i > 3)
	{
		push_b(stack_a, stack_b, 1);
		i++;
	}
}

 void organize_three (t_stack **stack_a)
 {
	int	highest;

	if (list_sorted(stack_a))
		return ;
	highest = highest_index(*stack_a);
	if ((*stack_a)->index == highest)
		rotate_a(stack_a, 1);
	else if ((*stack_a)->next->index == highest)
		reverse_rotate_a(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)-> next->index)
		swap_a(stack_a, 1);
 }

int highest_index(t_stack *stack_a)
{
	int	index;

	index = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index > index)
			index = stack_a->index;
		stack_a = stack_a->next;
	}
	return (index);
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
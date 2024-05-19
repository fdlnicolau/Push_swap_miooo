/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/06 22:55:02 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 10:55:25 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	min_steps(t_stack **stack_a)
{
	int	index;
	int	min_steps;
	int	current_steps;
	int	i;

	index = 0;
	i = -1;
	min_steps = 2147483647;
	while ( ++i < stack_size(*stack_a))
	{
		current_steps = node_at_index(*stack_a, i)->cost_total;
		if (current_steps < min_steps)
		{
			min_steps = current_steps;
			index = i;
		}
	}
	return (index);
}

int	get_target_index(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_stack	*copy_b;
	int		last_value;
	int		index;
	int		i;

	index = 0;
	copy_b = stack_b;
	i = -1;
	if (stack_a->value < min(stack_b) || stack_a->value > max(stack_b))
		index = find_value_index(stack_b, max(stack_b));
	else
	{
		last_value = node_at_index(stack_b, size - 1)->value;
		while (copy_b->next)
		{
			i++;
			if (stack_a->value < copy_b->value && stack_a->value > copy_b->next->value)
				index = i + 1;
			else if (stack_a->value < last_value && stack_a->value > stack_b->value)
				index = 0;
			copy_b = copy_b->next;
		}
	}
	return (index);
}

int	min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
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

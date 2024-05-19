/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:50:45 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/19 20:06:05 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	combine(t_stack **stack_a, t_stack **stack_b, int pos)
{
	t_stack	*current;

	current = node_at_index(*stack_a, pos);
	if (current->cost_a * current->cost_b > 0)
	{
		while (current->cost_a != 0 && current->cost_b != 0)
		{
			if (current->cost_a > 0)
			{
				rotate_r(stack_a, stack_b, 1);
				current->cost_a--;
				current->cost_b--;
			}
			else
			{
				reverse_rotate_r(stack_a, stack_b, 1);
				current->cost_a++;
				current->cost_b++;
			}
		}
		total_steps(*stack_a);
		pos = min_steps(stack_a);
	}
	moving(stack_a, stack_b, pos);
}

void	cost_of_stack_b(t_stack *stack_a, t_stack *stack_b)
{
	int	target;
	int	size;

	size = stack_size(stack_b);
	while (stack_a)
	{
		target = get_target_index(stack_a, stack_b, size);
		if (target <= size / 2)
			stack_a->cost_b = target;
		else
			stack_a->cost_b = -(size - target);
		stack_a = stack_a->next;
	}
}

void	total_steps(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->cost_a * stack_a->cost_b < 0)
			stack_a->cost_total = abs_value(stack_a->cost_a)
				+ abs_value(stack_a->cost_b);
		else
		{
			if (abs_value(stack_a->cost_a) > abs_value(stack_a->cost_b))
				stack_a->cost_total = abs_value(stack_a->cost_a);
			else
				stack_a->cost_total = abs_value(stack_a->cost_b);
		}
		stack_a = stack_a->next;
	}
}

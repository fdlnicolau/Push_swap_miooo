/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/04/24 14:28:58 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 15:54:09 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	order_b(t_stack **stack_b)
{
	while (*stack_b && (*stack_b)->value != max(*stack_b))
	{
		if (find_value_index(*stack_b, max(*stack_b)) <= stack_size(*stack_b) / 2)
			rotate_b(stack_b, 1);
		else
			reverse_rotate_b(stack_b, 1);
	}
}

int	find_value_index(t_stack *stack, int value)
{
	int	i;

	i = -1;
	while (stack)
	{
		i++;
		if (stack->value == value)
			return (i);
		stack = stack->next;
	}
	return (-1);
}

t_stack	*node_at_index(t_stack *stack, int index)
{
	while (index-- > 0)
		stack = stack->next;
	return (stack);
}

void	cost_of_stack_a(t_stack *stack_a)
{
	int	pos;
	int	size;

	size = stack_size(stack_a);
	pos = 0;
	while (stack_a)
	{
		if (pos <= size / 2)
			stack_a->cost_a = pos;
		else
			stack_a->cost_a = pos - size;
		stack_a = stack_a->next;
		pos++;
	}
}

int	get_target(t_stack **stack_a, int b_idx, int target_indx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_indx != INT_MAX)
		return (target_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

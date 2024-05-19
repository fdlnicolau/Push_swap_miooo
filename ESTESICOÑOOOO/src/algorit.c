/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:48:57 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/19 20:19:54 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	best_algorit(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i <= 1 || list_sorted(*stack_a))
		return ;
	if (i == 2)
		swap_a(stack_a, 1);
	else if (i == 3)
		organize_three(stack_a);
	else if (i < 6)
		sort(stack_a, stack_b);
	else
		large_stack(stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;

	while (stack_size(*stack_a) > 3)
	{
		smallest = find_value_index(*stack_a, min(*stack_a));
		if (smallest == 0)
			push_b(stack_a, stack_b, 1);
		else if (smallest < stack_size(*stack_a) / 2)
			rotate_a(stack_a, 1);
		else
			reverse_rotate_a(stack_a, 1);
	}
	organize_three(stack_a);
	while (stack_size(*stack_b))
		push_a(stack_b, stack_a, 1);
}

void	large_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	pos;

	push_b(stack_a, stack_b, 1);
	push_b(stack_a, stack_b, 1);
	while (stack_size(*stack_a) > 0)
	{
		cost_of_stack_a(*stack_a);
		cost_of_stack_b(*stack_a, *stack_b);
		total_steps(*stack_a);
		pos = min_steps(stack_a);
		combine(stack_a, stack_b, pos);
		push_b(stack_a, stack_b, 1);
	}
	order_b(stack_b);
	last_step(stack_a, stack_b);
}

void	moving(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int	i;

	i = 0;
	while (i < abs_value(node_at_index(*stack_a, pos)->cost_a))
	{
		if (node_at_index(*stack_a, pos)->cost_a > 0)
			rotate_a(stack_a, 1);
		else
			reverse_rotate_a(stack_a, 1);
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (i < abs_value(node_at_index(*stack_a, pos)->cost_b))
	{
		if (node_at_index(*stack_a, pos)->cost_b > 0)
			rotate_b(stack_b, 1);
		else
			reverse_rotate_b(stack_b, 1);
		i++;
	}
}

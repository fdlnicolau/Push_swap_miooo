/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:51 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 15:59:17 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void rotate_a(t_stack **stack_a, int flag)
{
	if(!(*stack_a) || (!(*stack_a)-> next))
		return;
	if ((*stack_a)->cost_a > 0)
		{
			rotate(stack_a);
			(*stack_a)->cost_a--;
			if(flag == 1)
				ft_printf("ra\n");
		}
	else if ((*stack_a)->cost_a < 0)
		{
			reverse_rotate(stack_a);
			(*stack_a)->cost_a++;
			if(flag == 1)
				ft_printf("rra\n");
		}

	
}
void rotate_b(t_stack **stack_b, int flag)
{
	if(!(*stack_b) || (!(*stack_b)-> next))
		return;
	if ((*stack_b)->cost_b > 0)
		{
			rotate(stack_b);
			(*stack_b)->cost_b--;
			if(flag == 1)
				ft_printf("rb\n");
		}
	else if ((*stack_b)->cost_b < 0)
		{
			reverse_rotate(stack_b);
			(*stack_b)->cost_b++;
			if(flag == 1)
				ft_printf("rrb\n");
		}
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b, int flag)
{
	while((*stack_a)->cost_a > 0 && (*stack_b)->cost_b > 0)
	{
		(*stack_a)->cost_a--;
		(*stack_b)->cost_b--;
		rotate(stack_a);
		rotate(stack_b);
		if (flag == 1)
			ft_printf("rr\n");
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack_size(*stack) > 1)
	{
		first = *stack;
		if(!first || (!first-> next))
			return;
		*stack = first->next;
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

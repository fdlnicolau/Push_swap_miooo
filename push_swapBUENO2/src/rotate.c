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


void	cost_rotate_a(t_stack **stack_a, int *cost)
{
	while(*cost)
	{
		if(*cost > 0)
		{
			rotate_a(stack_a, 1);
			(*cost)--;
		}
		else if(*cost < 0)
		{
			reverse_rotate_a(stack_a, 1);
			(*cost)++;
		}
	}
}

void cost_rotate_b(t_stack **stack_b, int *cost)
{
	while(*cost)
	{
		if(*cost > 0)
		{
			rotate_b(stack_b, 1);
			(*cost)--;
		}
		else if(*cost < 0)
		{
			reverse_rotate_b(stack_b, 1);
			(*cost)++;
		}
	}
}
void rotate_a(t_stack **stack_a, int flag)
{
	rotate(stack_a);
	if(flag == 1)
	ft_printf("ra\n");
}
void rotate_b(t_stack **stack_b, int flag)
{
	if(!(*stack_b) || (!(*stack_b)-> next))
		return;
	rotate(stack_b);
	if(flag == 1)
	ft_printf("rb\n");
}

void	cost_rotate_r(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while(*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rotate_r(stack_a, stack_b, 1);
	}
}
void	cost_reverse_r(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		reverse_rotate_r(stack_a, stack_b, 1);
	}
}

void	rotate_r(t_stack **stack_a, t_stack **stack_b, int flag)
{
		rotate(stack_a);
		rotate(stack_b);
		if (flag == 1)
			ft_printf("rr\n");
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

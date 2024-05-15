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
	t_stack *first;
	t_stack *last;

	if(!(*stack_a) || (!(*stack_a)-> next))
		return;
	rotate(stack_a);
	if(flag == 1)
		ft_printf("ra\n");
	
}
void rotate_b(t_stack **stack_b, int flag)
{
	t_stack *first;
	t_stack *last;
	
	if(!(*stack_b) || (!(*stack_b)-> next))
		return;
	rotate(stack_b);
	if(flag == 1)
		ft_printf("rb\n");
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
		last = *stack;
		*stack = first->next;
		while (last->next)
			last = last->next;
		last->next = first;
		first->next = NULL;
	}
}

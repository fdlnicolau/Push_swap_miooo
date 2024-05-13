/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:51 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/06 23:42:12 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void rotate_a(t_stack **stack_a, int flag)
{
	t_stack *first;
	t_stack *last;

	if(!(*stack_a) || (!(*stack_a)-> next))
		return;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while(last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;

	if(flag == 1)
		ft_printf("ra\n");
	
}
void rotate_b(t_stack **stack_b, int flag)
{
	t_stack *first;
	t_stack *last;
	
	first = *stack_b;
	last = *stack_b;
	while(last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	
	if(flag == 1)
		ft_printf("rb\n");
}
void	rotate_rt(t_stack **stack_a, t_stack **stack_b, int flag)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);

	if(flag == 1)
		ft_printf("rr\n");
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

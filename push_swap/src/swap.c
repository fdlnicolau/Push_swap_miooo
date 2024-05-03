/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:17:45 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/02 17:20:17 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_a(t_stack **stack_a, int flag)
{
	swap(stack_a);
	if(flag == 1)
		ft_printf("sa\n");
}
void swap(t_stack **stack)
{
	t_stack	*tmp;
	if(stack_size(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->next = tmp;
	}
}
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


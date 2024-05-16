/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:42:06 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 15:50:20 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate_b(t_stack **stack_b, int flag)
{
	reverse_rotate(stack_b);
	if (flag == 1)
		ft_printf("rrb\n");
}
void	reverse_rotate_a(t_stack **stack_a, int flag)
{
	reverse_rotate(stack_a);
	if (flag == 1)
		ft_printf("rra\n");
}
void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;
	
	if (!*stack || !(*stack)->next)
		return ;
	if (*stack && (*stack)->next)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		first = *stack;
		while (first->next != last)
			first = first->next;
		first->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, int flag)
{
	while((*stack_a)->cost_a < 0 && (*stack_b)->cost_b < 0)
	{
		(*stack_a)->cost_a++;
		(*stack_b)->cost_b++;
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		if (flag == 1)
			ft_printf("rrr\n");
	}
}

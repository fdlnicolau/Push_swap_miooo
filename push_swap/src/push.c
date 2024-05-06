/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:07:38 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/06 23:40:56 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag == 1)
		ft_printf("pa\n");
}

void push_b (t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	if(*stack_a != NULL)
	{
		tmp = *stack_b;
		*stack_b = *stack_a;
		(*stack_b)->next = tmp;
		*stack_a = (*stack_a)->next;
	}
}

void	push(t_stack **stack_one, t_stack **stack_two)
{
	t_stack	*tmp;

	if (stack_size(*stack_two) >= 1)
	{
		tmp = *stack_two;
		*stack_two = (*stack_two)->next;
		tmp->next = *stack_one;
		*stack_one = tmp;
	}
}
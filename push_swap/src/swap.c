/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:17:45 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 15:48:50 by lnicolau         ###   ########.fr       */
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
	t_stack	*first;
	t_stack *second;
	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	if(stack_size(*stack) > 1)
	{
		first = *stack;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack = second;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:17:45 by lnicolau          #+#    #+#             */
/*   Updated: 2024/04/25 15:35:24 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	swap_a(t_stack **stack_a, int flag)
{
	swap(stack_a);
	if(flag == 1)
		ft_printf("sa\n");
}
void swap(t_stack **stack)
{
	t_stack	*tmp;
	if(stacksize(*stack) > 1)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		(*stack)->next = tmp;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/06 22:07:38 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 15:36:55 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_a(t_stack **stack_b, t_stack **stack_a, int flag)
{
	push(stack_b, stack_a);
	if (flag == 1)
		ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b, int flag)
{
	push(stack_a, stack_b);
	if (flag == 1)
		ft_printf("pb\n");
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	tmp = (*src)->next;
	if (!(*src) || !(*src) || !dst)
		return ;
	if (!*dst)
	{
		(*src)->next = NULL;
		*dst = *src;
		*src = tmp;
	}
	else
	{
		(*src)->next = *dst;
		*dst = *src;
		*src = tmp;
	}
}

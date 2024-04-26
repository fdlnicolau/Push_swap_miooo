/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:28:58 by lnicolau          #+#    #+#             */
/*   Updated: 2024/04/24 16:24:07 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int list_sorted (t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if(!tmp)
		return(TRUE); //indicar que una lista vacía se considera ordenada.
	
	while(tmp && tmp->next)
	{
		if(tmp->values > tmp->next->values)
			return(FALSE);
		tmp = tmp->next;
	}
	return(TRUE);
}

void	best_algorit(t_stack **stack_a, t_stack **stack_b, int i)
{
	if(i = 2)
		swap_a(stack_a, 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:28:58 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/03 18:06:10 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int list_sorted (t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if(!tmp)
		return(TRUE); //indicar que una lista vacía se considera ordenada.
	
	while(tmp && tmp->next)//mientras haya numeros en la pila
	{
		if(tmp->value > tmp->next->value)
			return(FALSE);
		tmp = tmp->next;
	}
	return(TRUE);
}


void preparation_of_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int push;

	size = stack_size(*stack_a);
	push = 0;
	
	while(size > 6 && push < size / 2)//para la eficiencia
	{
		if((*stack_a)-> index < size / 2)
		{
			push_b(stack_a, stack_b);
			push++;
		}
		else
			rotate_a(stack_a, 1);
	}
	while(size - push > 3)
	{
		push_b(stack_a, stack_b);
		push ++;
	}
}
int stack_size(t_stack *stack)
{
	int i;
	t_stack *current;
	
	i = 0;
	if(!stack)
		return(FALSE);
	current = stack;
	while(current->next)
	{
			i++;
			current = current->next;
	}
	return(i);
	
}
void	best_algorit(t_stack **stack_a, t_stack **stack_b, int i)
{
	if(i == 2)
		swap_a(stack_a, 1);//que los intercambia 
	if(i == 3)
		organize_three(stack_a);
	if(i > 3)
		put_index(*stack_a);//marca un indice a cada pila del satck_a
		printValuesAndIndices(*stack_a);
		preparation_of_numbers(stack_a, stack_b);
		organize_three(stack_a);
		while(stack_size(*stack_b) > 0)
		{
			assign_position(stack_a);
			assign_position(stack_b);
			calculate_objectives(stack_a, stack_b);
			calculate_cost(stack_a, stack_b);
		}

}

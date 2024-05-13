/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   org_pre_ass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:36 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/13 13:33:49 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void preparation_of_numbers(t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int push;
	int i;

	size = stack_size(*stack_a);
	push = 0;
	i = 0;
	
	while(size > 6 && i < size && push < size / 2)
	{
		if((*stack_a)->index < size / 2)
		{
			push_b(stack_a, stack_b);
			push++;
		}
		else
			rotate_a(stack_a, 1);
		i++;
	}
	while(size - push > 3)
	{
		push_b(stack_a, stack_b);
		push ++;
	}
}

 void organize_three (t_stack **stack_a)
{
	t_stack *first;
	t_stack *second;
	t_stack *third;

	first = *stack_a;
	second = first->next;
	third = second->next;

	if (first->value > second->value && first->value > third->value) 
	{
		rotate_a(stack_a, 1);
		organize_three(stack_a);
	}
	else if (first->value < second->value && second->value > third->value) 
	{
		reverse_rotate_a(stack_a, 1);
		organize_three(stack_a);
	}
	else if (first->value > second->value && first->value < third->value) 
		swap_a(stack_a, 1);	
}

void organize_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;
	cheapest = calculate_cheapest(stack_b);
	stack_a = stack_b;//puesto pa compilar
    while(cheapest->cost_a < 0 && cheapest->cost_b)
	 {
	 	reverse_rotate_r(stack_a, stack_b, 1);
	 	cheapest->cost_a++;
		cheapest->cost_b++;
	}
	while(cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rotate_r(stack_a, stack_b, 1);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	rotate_a_if(stack_a, &(cheapest->cost_a));
	rotate_b_if(stack_a, &(cheapest->cost_b));
	push_a(stack_a, stack_b, 1);
	
	
}

void	last_step(t_stack **stack_a)
{
    int	first;
    int	size;
    long last;
    long min_value;

    last = LONG_MIN;
    size = stack_size(*stack_a);
    min_value = min_index(*stack_a, last);
    unsigned_index(*stack_a, min_value, 0); // Asigna el índice 0 al nodo con el valor min_value
    first = 0; // Ahora sabemos que el nodo con el valor min_value tiene el índice 0
    if (first > size / 2)
    {
        while ((*stack_a)->index != first)
            reverse_rotate_a(stack_a, 1);
    }
    else
    {
        while ((*stack_a)->index != first)
            rotate_a(stack_a, 1); // Deberías usar rotate_a en lugar de reverse_rotate_a aquí
    }
}
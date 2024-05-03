/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:47:51 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/02 17:15:15 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void organize_three (t_stack **stack_a)
{
    t_stack *first;
    t_stack *second;
    t_stack *third;
	
    first = *stack_a;
    second = first->next;
    third = second->next;
	
    if (first->value > second->value && first->value > third->value) {
        // Si el primer elemento es el más grande entre los tres, rota hacia arriba para dejar el segundo elemento en la parte superior
        rotate_a(stack_a, 1);
        organize_three(stack_a);
    }
    if (first->value < second->value && second->value > third->value) 
	{
        // Si el segundo elemento es el más grande entre los tres, rota hacia abajo para dejar el tercer elemento en la parte superior
        reverse_rotate_a(stack_a, 1);
        organize_three(stack_a);
    }
    if (first->value > second->value && first->value < third->value) {
        // Si el primer elemento es más grande que el segundo pero más pequeño que el tercero, intercambia los dos primeros elementos
        swap_a(stack_a, 1);
	}	
}

void assign_position(t_stack **stack)
{
	t_stack *current;
	int pos;
	
	current = *stack;
	pos = 1;

	while(current != NULL)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

t_stack *max_index(t_stack **stack_a)
{
	t_stack *copy;
	t_stack	*max_index;
	
	copy = *stack_a;
	max_index = *stack_a;

	while(copy)
	{
		if(copy->value > max_index->value)
			max_index = copy;
		copy = copy->next;
	}
	return(max_index);
	
}
t_stack *min_index(t_stack **stack_a)
{
	t_stack *copy;
	t_stack	*min_index;
	
	copy = *stack_a;
	min_index = *stack_a;

	while(copy)
	{
		if(copy->value < min_index->value)
			min_index = copy;
		copy = copy->next;
	}
	return(min_index);
	
}
void calculate_objectives(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *max_objetive;
	t_stack *copy_a;
	t_stack *copy_b;
	int rest;

	max_objetive = max_index(stack_a);

	copy_a = *stack_a;
	copy_b = *stack_b;
	
	while(copy_b)
	{
		if(copy_b-> index > max_objetive->index)
			copy_b->objetive = min_index(stack_a)->pos;
		rest = max_objetive->index - copy_b->index;
		calculate_near(copy_a, copy_b, &rest);
		copy_a = *stack_a;
		copy_b = copy_b->next;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   org_pre_ass.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:36 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/06 23:01:51 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

	size = stack_size(*stack_a);
	first = min_index(stack_a)->index;
	if (first > size / 2)
	{
		while ((*stack_a)->index < size)
			reverse_rotate_a(stack_a, 1);
	}
	else
	{
		while ((*stack_a)->index != 1)
			reverse_rotate_a(stack_a, 1);
	}
}
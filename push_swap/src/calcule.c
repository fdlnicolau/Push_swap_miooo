/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:28:58 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/13 14:25:40 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Selecciona y ejecuta el mejor algoritmo para ordenar la pila
void	best_algorit(t_stack **stack_a, t_stack **stack_b, int i)
{
	if(i == 2)
		swap_a(stack_a, 1);//que los intercambia 
	if(i == 3)
		organize_three(stack_a);
	if(i > 3)
		put_index(*stack_a);//marca un indice a cada pila del satck_a
		// printValuesAndIndices(*stack_a);
		preparation_of_numbers(stack_a, stack_b);
		// print_stack(*stack_a, *stack_b);
		organize_three(stack_a);
		// ft_printf("tatobien\n");
		while(stack_size(*stack_b) > 0)
		{
			assign_position(stack_a);
			assign_position(stack_b);
			calculate_objectives(stack_a, stack_b);
			calculate_cost(stack_a, stack_b);
			organize_stacks(stack_a, stack_b);
		}
		if(!list_sorted(stack_a))
		last_step(stack_a);

}

// Esta función calcula la diferencia entre los índices de los nodos en las listas copy_a y copy_b.
void calculate_near(t_stack *copy_a, t_stack *copy_b, int *rest)
{
	while(copy_a)
	{
		if(copy_b->pos < copy_a->pos)
		{
			if(copy_a->pos - copy_b->pos <= *rest)
			{
				*rest = copy_a->pos - copy_b->pos;
				copy_b->target = copy_a->target;
			}
		}
		copy_a = copy_a->next;
	}
}
// Calcula el costo de mover cada nodo a su posición objetivo en las pilas stack_a y stack_b
void calculate_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *copy_b;
	int		size_a;
	int		size_b;
	int 	refer_point_a;
	int 	refer_point_b;
	
	copy_b = *stack_b;
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	refer_point_a = check_par(size_a);
	refer_point_b = check_par(size_b);
	while(copy_b)
	{
		//calcula para la cabeza
		copy_b->cost_b = copy_b->pos - 1;
		if(copy_b->pos > refer_point_b)
			copy_b->cost_b = (size_b - copy_b->pos + 1) * -1;
		copy_b->cost_a = copy_b->index -1;
		//calcula para su posicion objetivo
		if(copy_b->index > refer_point_a)
			copy_b->cost_a = (size_a - copy_b->index + 1) * -1;
		copy_b = copy_b->next;
	}
}
t_stack *calculate_cheapest(t_stack **stack_b)
{
	t_stack *copy;
	t_stack *cheapest;
	int abs_value_copy;
	int abs_value_cheapest;

	copy = *stack_b;
	cheapest = copy;

	while(copy)
	{
		abs_value_copy = abs_value(copy->cost_a) + abs_value(copy->cost_b);
		abs_value_cheapest = abs_value(cheapest->cost_a) + abs_value(cheapest->cost_b);
		if(abs_value_copy < abs_value_cheapest)
			cheapest = copy;
		copy = copy->next;
	}
	return(cheapest);
}
void calculate_objectives(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*max_objective;
	t_stack	*copy_a;
	t_stack	*copy_b;
	int		rest;
	long	last;

	max_objective = max_index(stack_a);
	copy_a = *stack_a;
	copy_b = *stack_b;  
	while (copy_b)
	{
		last = min_index(*stack_a, LONG_MIN);
		if (copy_b->index > max_objective->index)
			copy_b->target = find_pos(*stack_a, last);
		rest = max_objective->index - copy_b->index;
		calculate_near(copy_a, copy_b, &rest);
		copy_a = *stack_a;
		copy_b = copy_b->next;
	}
}
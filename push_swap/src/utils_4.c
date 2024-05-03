/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:22:47 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/03 18:03:50 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void organize_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *cheapest;
	cheapest = calculate_cheapest(stack_b);
	stack_a = stack_b;//puesto pa compilar
	// while(cheapest->cost_a < 0 && cheapest->cost_b)
	// {
	// 	reverse_rotate_r(stack_a, stack_b, 1);
	// 	cheapest->cost_a++;
		
	// }
	
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

int abs_value(int num)
{
	if(num < 0)
		return(-num);
	else
		return(num);	
}

void	put_index(t_stack *stack_a)
{
	int			size;
	int			i;
	t_stack 	*aux;
	long		min;
	long		last;

	i = 1;
	last = MIN_INT - 1;
	size = stack_size(stack_a);
	aux = stack_a;
	
	while(i <= size)
	{
		min = MAX_INT;
		aux = stack_a;
		while(aux)
		{
			if(aux->value < min && aux->value > last)
				min = aux->value;
			aux = aux->next;
		}
		unsigned_index(stack_a, min, i);
		last = min;
		i++;
	}
}

void unsigned_index(t_stack *stack_a, long min, int index)
{
	t_stack *aux;
	aux = stack_a;
	while(aux != NULL)
	{
		if(aux->value == min)
			aux->index = index;
		aux = aux->next;
	}
}

#include <stdio.h>

void printValuesAndIndices(t_stack *head) 
{
			ft_printf("tomalacasito\n");
	write(1, "hola", 4);
    t_stack *current = head;

    while (current != NULL) {
        printf("Value: %ld, Index: %d\n", current->value, current->index);
        current = current->next;
    }
}
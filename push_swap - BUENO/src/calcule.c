/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcule.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:28:58 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 15:54:09 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Selecciona y ejecuta el mejor algoritmo para ordenar la pila
void	best_algorit(t_stack **stack_a, t_stack **stack_b, int i)
{
	if(i == 2)
		swap_a(stack_a, 1);//que los intercambia
	if(i == 3)
	{
		organize_three(stack_a);
		print_stack(*stack_a,*stack_b);
	}
	if(i > 3)
	{
		put_index(*stack_a);//marca un indice a cada pila del satck_a
		//printValuesAndIndices(*stack_a);
		preparation_of_numbers(stack_a, stack_b);
		organize_three(stack_a);
		print_stack(*stack_a,*stack_b);
		// ft_printf("tatobien\n");
/* 		reverse_rotate_a(stack_a, 1);
		print_stack(*stack_a,*stack_b);
		printf("tamaño de B: %d\n", stack_size(*stack_b));
		reverse_rotate_b(stack_b, 1);
		print_stack(*stack_a,*stack_b);
		printf("tamaño de B: %d\n", stack_size(*stack_b));
		reverse_rotate_r(stack_a, stack_b, 1);
		print_stack(*stack_a,*stack_b);
		printf("tamaño de B: %d\n", stack_size(*stack_b)); */
		while(stack_size(*stack_b) > 0)
		{	
			assign_position(stack_a);
			assign_position(stack_b);
			calculate_objectives(stack_a, stack_b);
			calculate_cost(stack_a, stack_b);
			calculate_cheapest(stack_a, stack_b);
			print_stack(*stack_a,*stack_b);
		}
		printf("Despues\n");
		print_stack(*stack_a,*stack_b);
		printf("aAAAAAaaaa\n");
		if(!list_sorted(stack_a))
			last_step(stack_a);
		print_stack(*stack_a,*stack_b);
	}
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
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = stack_size(tmp_a);
	size_b = stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target;
		if (tmp_b->target > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target) * -1;
		tmp_b = tmp_b->next;
	}
}
void calculate_cheapest(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	int		ch;

	tmp = *stack_b;
	ch = INT_MAX;
	while (tmp)
	{
		if (abs_value(tmp->cost_a) + abs_value(tmp->cost_b) < abs_value(ch))
		{
			ch = abs_value(tmp->cost_b) + abs_value(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	moving(stack_a, stack_b, cost_a, cost_b);
}

void	moving(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		while(cost_a < 0 && cost_b < 0)
		{
			cost_a++;
			cost_b++;
			reverse_rotate_r(stack_a, stack_b, 1);
		}
	else if (cost_a > 0 && cost_b > 0)
		rotate_r(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a(stack_a, &cost_a);
	rotate_b(stack_b, &cost_b);
	push_a(stack_a, stack_b);
}
//aqui da bucle
void calculate_objectives(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(stack_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target = target_pos;
		tmp_b = tmp_b->next;
	}
}

int	get_target(t_stack **stack_a, int b_idx, int target_indx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_indx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_indx)
		{
			target_indx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

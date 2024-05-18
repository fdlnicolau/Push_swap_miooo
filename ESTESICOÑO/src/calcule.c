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
	if (i <= 1 || list_sorted(*stack_a))
		return ;
	if(i == 2)
		swap_a(stack_a, 1);
	else if(i == 3)
		organize_three(stack_a);
	else if(i < 6)
		sort(stack_a, stack_b);
	else
	{
		print_stack(*stack_a, *stack_b);
		printf("aquieh\n");
		large_stack(stack_a, stack_b);
	}
}

void large_stack(t_stack **stack_a, t_stack **stack_b)
{
	int pos;

	print_stack(*stack_a, *stack_b);
	printf("aquieh2\n");
	push_b(stack_a, stack_b, 1);
	push_b(stack_a, stack_b, 1);
	print_stack(*stack_a, *stack_b);
	printf("aquieh3\n");
	while(stack_size(*stack_a) > 0)
	{
		print_stack(*stack_a, *stack_b);
		printf("aquieh4\n");
		count_steap_a(*stack_a);
		count_steap_b(*stack_a, *stack_b);
		total_steps(*stack_a);
		pos = min_steps(stack_a);
		combine(stack_a, stack_b, pos);
		push_b(stack_a, stack_b, 1);
	}
	order_b(stack_b);
	last_step(stack_a, stack_b);
	print_stack(*stack_a, *stack_b);
	printf("aquieh3\n");
}

void order_b(t_stack **stack_b)
{
	while (*stack_b && (*stack_b)->value != max(*stack_b))
	{
		if (find_value_index(*stack_b, max(*stack_b)) <= stack_size(*stack_b) / 2)
			rotate_b(stack_b, 1);
		else
			reverse_rotate_b(stack_b, 1);
	}
}
void combine(t_stack **stack_a, t_stack **stack_b, int pos)
{
	t_stack	*current;

	current = node_at(*stack_a, pos);
	if (current->cost_a * current->cost_b > 0)
	{
		while (current->cost_a != 0 && current->cost_b != 0)
		{
			if (current->cost_a > 0)
			{
				rotate_r(stack_a, stack_b, 1);
				current->cost_a--;
				current->cost_b--;
			}
			else
			{
				reverse_rotate_r(stack_a, stack_b, 1);
				current->cost_a++;
				current->cost_b++;
			}
		}
		total_steps(*stack_a);
		pos = min_steps(stack_a);
	}
	moving(stack_a, stack_b, pos);
}

int min_steps(t_stack **stack_a)
{
	int	index;
	int	min_steps;
	int	current_steps;
	int	i;

	index = 0;
	i = -1;
	min_steps = 2147483647;
	while (++i < stack_size(*stack_a))
	{
		current_steps = node_at_index(*stack_a, i)->cost_total;
		if (current_steps < min_steps)
		{
			min_steps = current_steps;
			index = i;
		}
	}
	return (index);
}
t_stack	*node_at(t_stack *stack, int index)
{
	while (index-- > 0)
		stack = stack->next;
	return (stack);
}

void count_steap_b(t_stack *stack_a, t_stack *stack_b)
{
	int	target;
	int	size;

	size = stack_size(stack_b);
	while (stack_a)
	{
		target = get_target_index(stack_a, stack_b, size);
		if (target <= size / 2)
			stack_a->cost_b = target;
		else
			stack_a->cost_b = -(size - target);
		stack_a = stack_a->next;
	}
}

void	total_steps(t_stack *stack_a)
{
	while (stack_a)
	{
		if (stack_a->cost_a * stack_a->cost_b < 0)
			stack_a->cost_total = abs_value(stack_a->cost_a) + abs_value(stack_a->cost_b);
		else
		{
			if (abs_value(stack_a->cost_a) > abs_value(stack_a->cost_b))
				stack_a->cost_total = abs_value(stack_a->cost_a);
			else
				stack_a->cost_total = abs_value(stack_a->cost_b);
		}
		stack_a = stack_a->next;
	}
}

int get_target_index(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_stack	*copy_b;
	int		last_value;
	int		index;
	int		i;

	index = 0;
	copy_b = stack_b;
	i = -1;
	if (stack_a->value < min(stack_b) || stack_a->value > max(stack_b))
		index = find_value_index(stack_b, max(stack_b));
	else
	{
		last_value = node_at_index(stack_b, size - 1)->value;
		while(copy_b->next)
		{
			i++;
			if(stack_a->value < copy_b->value && stack_a->value > copy_b->next->value)
				index = i + 1;
			else if(stack_a->value < last_value && stack_a->value > stack_b->value)
				index = 0;
			copy_b = copy_b->next;		
		}
	}
	return (index);
}

int min(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->value;
	while(stack)
	{
		if(stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int max(t_stack *stack)
{
	int	max;

	if (!stack)
		return (0);
	max = stack->value;
	while(stack)
	{
		if(stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_value_index(t_stack *stack, int value)
{
	int	i;

	i = -1;
	while (stack)
	{
		i++;
		if (stack->value == value)
			return (i);
		stack = stack->next;
	}
	return (-1);
}
t_stack *node_at_index(t_stack *stack, int index)
{
	while (index-- > 0)
		stack = stack->next;
	return (stack);
}
void count_steap_a(t_stack *stack_a)
{
	int	pos;
	int	size;

	size = stack_size(stack_a);
	pos = 0;
	while (stack_a)
	{
		if (pos <= size / 2)
			stack_a->cost_a = pos;
		else
			stack_a->cost_a = pos - size;
		stack_a = stack_a->next;
		pos++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int smallest;

	while(stack_size(*stack_a) > 3)
	{	
		smallest = find_value_index(*stack_a, min(*stack_a));
		if (smallest == 0)
			push_b(stack_a, stack_b, 1);
		else if (smallest < stack_size(*stack_a) / 2)
			rotate_a(stack_a, 1);
		else
			reverse_rotate_a(stack_a, 1);
	}
	organize_three(stack_a);
	print_stack(*stack_a, *stack_b);
	while(stack_size(*stack_b))
		push_a(stack_b, stack_a, 1);
	print_stack(*stack_a, *stack_b);
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
/* void calculate_cheapest(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;
	int		cost_a;
	int		cost_b;
	int		cheap;

	tmp = *stack_b;
	cheap = INT_MAX;
	while (tmp)
	{
		if (abs_value(tmp->cost_a) + abs_value(tmp->cost_b) < abs_value(cheap))
		{
			cheap = abs_value(tmp->cost_b) + abs_value(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	moving(stack_a, stack_b, cost_a, cost_b);
} */

void	moving(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int	i;

	i = 0;
	while (i < abs_value(node_at_index(*stack_a, pos)->cost_a))
	{
		if (node_at_index(*stack_a, pos)->cost_a > 0)
			rotate_a(stack_a, 1);
		else
			reverse_rotate_a(stack_a, 1);
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (i < abs_value(node_at_index(*stack_a, pos)->cost_b))
	{
		if (node_at_index(*stack_a, pos)->cost_b > 0)
			rotate_b(stack_b, 1);
		else
			reverse_rotate_b(stack_b, 1);
		i++;
	}
}
//aqui da bucle
void calculate_objectives(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	assign_position(stack_a);
	assign_position(stack_b);
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
	tmp_a = *stack_a;
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

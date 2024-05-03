/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:36 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/03 15:08:08 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void calculate_near(t_stack *copy_a, t_stack *copy_b, int *rest)
{
	while(copy_a)
	{
		if(copy_b->index < copy_a->index)
		{
			if(copy_a->index - copy_b->index <= *rest)
			{
				*rest = copy_a->index - copy_b->index;
				copy_b->target = copy_a->pos;
			}
		}
		copy_a = copy_a->next;
	}
}

void push_b (t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;
	if(*stack_a != NULL)
	{
		tmp = *stack_b;
		*stack_b = *stack_a;
		(*stack_b)->next = tmp;
		*stack_a = (*stack_a)->next;
	}
}
void reverse_rotate_a(t_stack **stack_a, int flag)
{
	t_stack *first;
	t_stack *last;
	t_stack *alast;

	if(!(*stack_a) || (!(*stack_a)-> next))
		return;
	first = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	alast = first;
	while(last->next)
		last = last->next;
	while(alast->next != last)
		alast = alast->next;	
	*stack_a = last;
	(*stack_a)->next = first;
	alast->next = NULL;
	if(flag == 1)
		ft_printf("rra\n");
		
}
int check_par(int size)
{
	int 	result;
    if (size % 2 == 0)
        result = size / 2;
    else
        result = (size / 2) + 1;
	return (result);
}

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
		copy_b->cost_a = copy_b->target -1;
		//calcula para su posicion objetivo
		if(copy_b->target > refer_point_a)
			copy_b->cost_a = (size_a - copy_b->target + 1) * -1;
		copy_b = copy_b->next;
	}
}

 #include <stdio.h>

 void print_stack(t_stack* stack_a, t_stack* stack_b) {
     t_stack* current_node;
     printf("Stack A: ");
     current_node = stack_a;
	 
     while (current_node != NULL) {
         printf("%ld ", current_node->value);
         current_node = current_node->next;
     }
     printf("\n");

     printf("Stack B: ");
     current_node = stack_b;
     while (current_node != NULL) {
         printf("%ld ", current_node->value);
         current_node = current_node->next;
     }
     printf("\n");
 }
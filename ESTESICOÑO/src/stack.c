/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:22:47 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 10:44:05 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int abs_value(int num)
{
	if(num < 0)
		return(-num);
	else
		return(num);	
}
 //Verificar si la lista está ordenada correctamente
 int list_sorted (t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

// esta función agrega un nuevo nodo a una pila de tipo t_stack con el
//  valor especificado, realizando las comprobaciones necesarias para manejar
//   errores como la falta de memoria o valores fuera de rango.
void add_node_back(t_stack **stack, t_stack *new_node)
{
    t_stack *tmp;

    tmp = *stack;
    if (!tmp)
    {
        *stack = new_node;
        return;
    }
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new_node;
}

/* t_stack	*transfer_stack(char *string_value, t_stack **ptr_stack)
{
    t_stack 	*new_node;
    long 		value;

    value = ft_atol(string_value);
    if (check_dupli(*ptr_stack, value) == FALSE)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
    if (value < -2147483648 || value > 2147483647)
            return (NULL);

    new_node = create_node(value);
    add_node_back(ptr_stack, new_node);
    return (*ptr_stack);
} */
t_stack *create_node(long value)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
	if (!new_node)
	{
		ft_putendl_fd("stack bad", 2);
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->cost_total = 0;
	return(new_node);
}
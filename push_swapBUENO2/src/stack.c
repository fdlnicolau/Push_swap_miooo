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
	if (num < 0)
		return (num * -1);
	return (num);
}
 //Verificar si la lista está ordenada correctamente
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

// esta función agrega un nuevo nodo a una pila de tipo t_stack con el
//  valor especificado, realizando las comprobaciones necesarias para manejar
//   errores como la falta de memoria o valores fuera de rango.
/* t_stack	*transfer_stack(char *string_value, t_stack *ptr_stack)
{
	t_stack 	*current;
	t_stack 	*new_node;
	long 		value;
	
	value = ft_atol(string_value);
	if (value < -2147483648 || value > 2147483647)
			return (NULL);
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node == NULL)
		return(NULL);
	new_node->value = value;
	new_node->next = NULL;

	if(ptr_stack == NULL)
		ptr_stack = new_node;
	else
	{
		current = ptr_stack;
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	return(ptr_stack);
} */
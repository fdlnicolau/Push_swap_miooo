/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:03:37 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/13 13:42:18 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	ft_atol(const char *str)
{
	long	digit;
	int		i;
	int		sig;

	i = 0;
	digit = 0;
	sig = 1;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = (digit * 10) + (str[i] - '0');
		i++;
	}
	return (digit * sig);
}
//calcula y devuelve el tamaño de la pila
int stack_size(t_stack *stack)
{
	int i;
	t_stack *current;
	
	i = 0;
	if(!stack)
		return(FALSE);
	current = stack;
	while(current)
	{
			i++;
			current = current->next;
	}
	return(i);
	
}
void assign_position(t_stack **stack)
{
	t_stack *current = *stack;
	int pos = 1;

	while (current != NULL)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}
int find_pos(t_stack *stack, long value) 
{
	int pos = 1;
	while (stack)
	{
		if (stack->value == value)
		{
			return(pos);
        }
		stack = stack->next;
		pos++;
    }
	return (-1); // Valor no encontrado
}

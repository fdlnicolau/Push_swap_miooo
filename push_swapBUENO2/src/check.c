/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:29:41 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/13 15:04:39 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int check_par(int size)
{
	int	result;
	if (size % 2 == 0)
		result = size / 2;
	else
		result = (size / 2) + 1;
	return (result);
}
int	is_valid_number(char **str)
{
	int	i;
	int	j;
	
	i =	0;
	while (str[i] != NULL)
	{
		j = 0;
		if ((str[i][j] == '+' || str[i][j] == '-')) 
			j++;
		while (str[i][j] != 0 && (str[i][j] <= '9' && str[i][j] >= '0'))
		{
			j++;
		}
		if (str[i][j] == '\0')
			i++;
		else
			return (FALSE);
	}
	return(TRUE);
}

//me mira que no este publicado
int	check_dupli(t_stack *stack_a)
{
	t_stack	*current;
	t_stack *current2;

	current = stack_a;
	while (current)
	{
		current2 = current->next;
		while(current2)
		{
			if (current->value == current2->value)
			{
				return (1);
			}
			current2 = current2->next;
		}
		current = current->next;
	}
	return (0);
}

//validar y procesar los argumentos de línea de comandos.
void check_argv(char *argv, t_stack **stack_a)
{
	char	**str;
	long int	n;
	int			i;
	
	str = ft_split(argv, ' ');
	i = 0;
	while (str[i] != (void *)0)
	{
		if(is_valid_number(&str[i]))
		{
			n = ft_atoi(str[i]);
			if (n > INT_MAX || n < INT_MIN)
				error_exit(stack_a, NULL);
			stack_add(stack_a, stack_new(n));
		}
		else
			error_exit(NULL, NULL);
		free(str[i]);
		i++;

	}
	free(str);
}

void	stack_add(t_stack **stack, t_stack *new)
{
	t_stack	*bottom;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	bottom = get_bottom(*stack);
	bottom->next = new;
}

t_stack	*get_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}
void	error_exit(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit(1);
}
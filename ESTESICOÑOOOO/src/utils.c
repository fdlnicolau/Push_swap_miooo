/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/06 23:03:37 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/13 13:42:18 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long int	ps_atoi(char *s)
{
	long int	res;
	int			sign;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (!s[i])
		error();
	while (ft_isdigit(s[i]))
		res = res * 10 + (s[i++] - '0');
	if (s[i] && !ft_isdigit(s[i]))
		error();
	return (res * sign);
}

int	stack_size(t_stack *stack)
{
	int		i;
	t_stack	*current;

	i = 0;
	if (!stack)
		return (FALSE);
	current = stack;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
}

void	assign_position(t_stack **stack)
{
	t_stack	*current;
	int		pos;

	current = *stack;
	pos = 1;
	while (current != NULL)
	{
		current->pos = pos;
		current = current->next;
		pos++;
	}
}

int	is_valid_number(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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
	return (TRUE);
}

int	abs_value(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

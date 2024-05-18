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
int	check_dupli(t_stack *stack_a, long value)
{
	t_stack	*current;

	current = stack_a;
	while (current != NULL)
	{
			if (current->value == value)
				return (FALSE);
		current = current->next;
	}
	return (TRUE);
}
//me mira todas las condiciones
void	check_all (char **str)
{
	int i;
	i = 0;
	while(str[i] != NULL)
	{
		if (is_valid_number(&str[i]) == FALSE)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

//validar y procesar los argumentos de línea de comandos.
void check_argv(char **argv)
{
	int		i;
	int		j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		if (ps_atoi(argv[i]) > INT_MAX || ps_atoi(argv[i]) < INT_MIN)
			error();
		while (argv[++j])
		{
			if (i != j && !compare_atoi(argv[i], argv[j]))
				error();
		}
	}
}

void error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}
long int	ps_atoi(char *s)
{
	long int	res;
	int			sign;
	int			i;

	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == 45)
	{
		sign *= -1;
		i++;
	}
	if (!s[i])
		error();
	while (ft_isdigit(s[i]))
		res = res * 10 + (s[i++] - 48);
	if (s[i] && !ft_isdigit(s[i]))
		error();
	return (res * sign);
}

int	compare_atoi(char *s1, char *s2)
{
	long int	i;
	long int	j;

	i = ps_atoi(s1);
	j = ps_atoi(s2);
	return (i - j);
}
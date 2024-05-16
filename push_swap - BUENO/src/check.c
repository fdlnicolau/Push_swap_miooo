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
char **check_argv(int argc, char **argv)
{
	char	**str;
	
	if (argc < 2)
		exit(EXIT_FAILURE);
	else if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if (str == NULL)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		check_all(str);
		return(str);
	}
	else
	{
		check_all(argv + 1);
		return(argv + 1);
	}
}
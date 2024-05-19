/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/05/06 22:29:41 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/13 15:04:39 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		if (is_valid_number(&str[i]) == FALSE)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_argv(char **argv)
{
	int	i;
	int	j;

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

int	compare_atoi(char *s1, char *s2)
{
	long int	i;
	long int	j;

	i = ps_atoi(s1);
	j = ps_atoi(s2);
	return (i - j);
}

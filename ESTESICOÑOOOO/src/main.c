/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/04/08 22:16:53 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 10:30:55 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	handle_stack(t_stack **stack_a, char **argv)
{
	t_stack	*new_node;

	while (*argv)
	{
		new_node = create_node(ft_atoi(*(argv++)));
		add_node_back(stack_a, new_node);
	}
	if (list_sorted(*stack_a))
		exit(0);
}

void	handle_algorithm(t_stack **stack_a, t_stack **stack_b)
{
	if (!list_sorted(*stack_a))
		best_algorit(stack_a, stack_b, stack_size(*stack_a));
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
		if (argc < 2)
			exit(0);
		if (argc == 2 && ft_strchr(argv[1], ' '))
			argv = ft_split(argv[1], ' ');
		else
			argv++;
	check_argv(argv);
	handle_stack(&stack_a, argv);
	handle_algorithm(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

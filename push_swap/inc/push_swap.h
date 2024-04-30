/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:18 by lnicolau          #+#    #+#             */
/*   Updated: 2024/04/30 16:06:31 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

# define FALSE 0
# define TRUE 1

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	int				value;
	int				index;
	int				pos;
	int				objetive;
}				t_stack;

void	init_program(t_stack ***stack_a, t_stack ***stack_b);
int is_valid_number(char **str);
int main (int argc, char **argv);
int	check_dupli(char **str);
void check_all (char **str);
char **check_argv(int argc, char **argv);

#endif
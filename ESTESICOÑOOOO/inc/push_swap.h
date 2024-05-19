/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:18 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 14:23:06 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>

# define FALSE 0
# define TRUE 1

# define MIN_INT -2147483648
# define MAX_INT 2147483647

typedef struct s_stack
{
	struct s_stack	*next;
	long			value;
	int				index;
	int				pos;
	int 			target;
	int				cost_a;
	int				cost_b;
	int				cost_total;
}					t_stack;

//FUNCIONES DE ALGORITMMO

void	best_algorit(t_stack **stack_a, t_stack **stack_b, int i);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	large_stack(t_stack **stack_a, t_stack **stack_b);
void	moving(t_stack **stack_a, t_stack **stack_b, int pos);

//FUNCIONES DE CALCULO

void	order_b(t_stack **stack_b);
int		find_value_index(t_stack *stack, int value);
t_stack	*node_at_index(t_stack *stack, int index);
int		get_target(t_stack **stack_a, int b_idx, int target_indx, int target_pos);

//CHEACKERS

void	check_all(char **str);
void	check_argv(char **argv);
int		compare_atoi(char *s1, char *s2);

//COSTES

void	combine(t_stack **stack_a, t_stack **stack_b, int pos);
void	cost_of_stack_b(t_stack *stack_a, t_stack *stack_b);
void	total_steps(t_stack *stack_a);
void	cost_of_stack_a(t_stack *stack_a);

//FREE

void	free_str(char **str);
void	free_stack(t_stack **stack);

//INDEX

int		min_steps(t_stack **stack_a);
int		get_target_index(t_stack *stack_a, t_stack *stack_b, int size);
int		min(t_stack *stack);
int		max(t_stack *stack);
int		glowest_i_p(t_stack **stack_a);


//MAIN

void	error(void);
void	handle_stack(t_stack **stack_a, char **argv);
void	handle_algorithm(t_stack **stack_a, t_stack **stack_b);
int	main(int argc, char **argv);

//ORGANIZE

void	organize_three(t_stack **stack_a);
void	last_step(t_stack **stack_a, t_stack **stack_b);

//PUSH

void	push_a(t_stack **stack_b, t_stack **stack_a, int flag);
void	push_b(t_stack **stack_a, t_stack **stack_b, int flag);
void	push(t_stack **src, t_stack **dst);

//REVERSE ROTATE

void	reverse_rotate_b(t_stack **stack_b, int flag);
void	reverse_rotate_a(t_stack **stack_a, int flag);
void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);
void	reverse_rotate(t_stack **stack);

//ROTATE

void	rotate_a(t_stack **stack_a, int flag);
void	rotate_b(t_stack **stack_b, int flag);
void	rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);
void	rotate(t_stack **stack);

//STACK

int		list_sorted(t_stack *stack);
void	add_node_back(t_stack **stack, t_stack *new_node);
t_stack	*create_node(long value);

//SWAP
void	swap_a(t_stack **stack_a, int flag);
void	swap(t_stack **stack);

//UTILS

long int	ps_atoi(char *s);
int			stack_size(t_stack *stack);
void		assign_position(t_stack **stack);
int			is_valid_number(char **str);
int			abs_value(int num);

//comprobaciones
void	printValuesAndIndices(t_stack *head);
void 	print_stack(t_stack* stack_a, t_stack* stack_b);
// void run_tests();

#endif
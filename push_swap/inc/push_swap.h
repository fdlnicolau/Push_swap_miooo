/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:49:18 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/06 23:48:12 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

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
	int				objetive;
	int				target;
	int				cost_a;
	int				cost_b;
}					t_stack;

int 		abs_value(int num);
void		assign_position(t_stack **stack);
void 		best_algorit(t_stack **stack_a, t_stack **stack_b, int i);
void 		calculate_cost(t_stack **stack_a, t_stack **stack_b);
void 		calculate_near(t_stack *copy_a, t_stack *copy_b, int *rest);
void 		calculate_objectives(t_stack **stack_a, t_stack **stack_b);
t_stack* 	calculate_cheapest(t_stack **stack_b);
int 		check_dupli(char **str);
int 		check_par(int size);
void 		check_all(char **str);
char** 		check_argv(int argc, char **argv);
int 		is_valid_number(char **str);
long 		ft_atol(const char *str);
void 		free_stack(t_stack **stack);
void 		free_str(char **str);
void		handle_algorithm(t_stack **stack_a, t_stack **stack_b);
void 		handle_stack(char **str, t_stack **stack_a);
void 		init_program(t_stack ***stack_a, t_stack ***stack_b);
void		last_step(t_stack **stack_a);
int 		list_sorted(t_stack **stack);
t_stack* 	max_index(t_stack **stack_a);
t_stack* 	min_index(t_stack **stack_a);
void 		organize_stacks(t_stack **stack_a, t_stack **stack_b);
void 		organize_three(t_stack **stack_a);
void 		preparation_of_numbers(t_stack **stack_a, t_stack **stack_b);
void 		push(t_stack **stack_one, t_stack **stack_two);
void 		push_a(t_stack **stack_a, t_stack **stack_b, int flag);
void 		push_b(t_stack **stack_a, t_stack **stack_b);
void		put_index(t_stack *stack_a);
void 		reverse_rotate(t_stack **stack);
void 		reverse_rotate_a(t_stack **stack_a, int flag);
void 		reverse_rotate_b(t_stack **stack_b, int flag);
void 		reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);
void 		rotate(t_stack **stack);
void 		rotate_a(t_stack **stack_a, int flag);
void 		rotate_a_if(t_stack **stack_a, int *cost_a);
void 		rotate_b(t_stack **stack_b, int flag);
void 		rotate_b_if(t_stack **stack_b, int *cost_b);
void		rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);
void 		rotate_rt(t_stack **stack_a, t_stack **stack_b, int flag);
int 		stack_size(t_stack *stack);
void 		swap(t_stack **stack);
void 		swap_a(t_stack **stack_a, int flag);
t_stack* 	transfer_stack(char *string_value, t_stack *ptr_stack);
void 		unsigned_index(t_stack *stack_a, long min, int index);




//comprobaciones
void		printValuesAndIndices(t_stack *head);
void 		print_stack(t_stack* stack_a, t_stack* stack_b);

#endif
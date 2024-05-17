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
}					t_stack;

// Funciones de Cálculo
int         abs_value(int num);
void        calculate_cheapest(t_stack **stack_b, t_stack **stack_a);
void        calculate_cost(t_stack **stack_a, t_stack **stack_b);
void        calculate_near(t_stack *copy_a, t_stack *copy_b, int *rest);
void        calculate_objectives(t_stack **stack_a, t_stack **stack_b);
int         find_pos(t_stack *stack, long value);
int         highest_index(t_stack *stack_a);
long        min_index(t_stack *stack_a, long last);
int         stack_size(t_stack *stack);
int         get_target(t_stack **a, int b_idx, int target_indx, int target_pos);

// Funciones de Comprobación
int         check_dupli(t_stack *stack_a);
void      	check_argv(char *argv, t_stack **stack_a);
int         check_par(int size);
int         is_valid_number(char **str);
int         list_sorted(t_stack **stack);

// Funciones de Manejo de Errores
void        error_exit(t_stack **stack_a, t_stack **stack_b);

// Funciones de Manejo de Memoria
void        free_stack(t_stack **stack);
void        free_str(char **str);
t_stack*		stack_new(int value);
void	stack_add(t_stack **stack, t_stack *new);
t_stack	*get_bottom(t_stack *stack);

// Funciones de Algoritmos y Ordenamiento
void        best_algorit(t_stack **stack_a, t_stack **stack_b, int i);
void        handle_algorithm(t_stack **stack_a, t_stack **stack_b, int i);
void        organize_stacks(t_stack **stack_a, t_stack **stack_b);
void        organize_three(t_stack **stack_a);
void        preparation_of_numbers(t_stack **stack_a, t_stack **stack_b);

// Funciones de Movimiento
void        moving(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
void        push(t_stack **stack_one, t_stack **stack_two);
void        push_a(t_stack **stack_a, t_stack **stack_b, int flag);
void        push_b(t_stack **stack_a, t_stack **stack_b, int flag);
void        reverse_rotate(t_stack **stack);
void        reverse_rotate_a(t_stack **stack_a, int flag);
void        reverse_rotate_b(t_stack **stack_b, int flag);
void        reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);
void        rotate(t_stack **stack);
void        rotate_a(t_stack **stack_a, int flag);
void        rotate_b(t_stack **stack_b, int flag);
void        rotate_r(t_stack **stack_a, t_stack **stack_b, int flag);
void        swap(t_stack **stack);
void        swap_a(t_stack **stack_a, int flag);

// Funciones de Cálculo de Costos de Movimiento
void        cost_reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);
void        cost_rotate_a(t_stack **stack_a, int *cost);
void        cost_rotate_b(t_stack **stack_b, int *cost);
void        cost_rotate_r(t_stack **stack_a, t_stack **stack_b, int *cost_a, int *cost_b);

// Funciones de Gestión de Índices
void        put_index(t_stack *stack_a, int size);
void        unsigned_index(t_stack *stack_a, long min, int index);

// Funciones de Manejo de la Pila
t_stack*    handle_stack(char **str);
t_stack*    transfer_stack(char *string_value, t_stack *ptr_stack);

// Otras Funciones
int         glowest_i_p(t_stack **stack_a);
long        ft_atol(const char *str);
void        last_step(t_stack **stack_a);
void        assign_position(t_stack **stack);




//comprobaciones
void		printValuesAndIndices(t_stack *head);
void 		print_stack(t_stack* stack_a, t_stack* stack_b);
// void run_tests();

#endif
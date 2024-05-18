/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:16:53 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/15 10:30:55 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
//  esta función toma los argumentos pasados al programa,
//   los procesa y los convierte en una pila A inicializada y poblada con esos datos.
//    Si ocurre algún error durante este proceso, se imprime un mensaje de error y el
//    programa termina con un código de error.
void handle_stack(t_stack **stack_a, char **argv)
{
		t_stack		*new_node;

		while (*argv)
		{
			new_node = create_node(ft_atoi(*(argv++)));
			add_node_back(stack_a, new_node);
		}
		if(list_sorted(*stack_a))
			exit(0);
}

// La función se encarga de procesar los argumentos
//  pasados al programa y convertirlos en una pila A inicializada
//   y poblada con esos datos. Si ocurre algún error durante este proceso
//   , como valores que no son números enteros o una falla en la asignación de memoria
//   , se imprime un mensaje de error y el programa termina
void handle_algorithm(t_stack **stack_a, t_stack **stack_b)
{
    if (!list_sorted(*stack_a)) 
        best_algorit(stack_a, stack_b, stack_size(*stack_a));
}

// maneja la entrada de argumentos, inicializa las pilas A y B, ejecuta un
//  algoritmo para ordenar las pilas y luego imprime el resultado.
int	main(int argc, char **argv)
{
    t_stack		*stack_a;
    t_stack 	*stack_b;
    
    stack_a = NULL;
    stack_b = NULL;

		if (argc < 2)
			exit(0);
		if (argc == 2 && ft_strchr(argv[1], 32))
			argv = ft_split(argv[1], 32);
		else
			argv++;
    check_argv(argv);
    handle_stack(&stack_a, argv);
    handle_algorithm(&stack_a, &stack_b);
	print_stack(stack_a, stack_b);
		
    return(0);
} 

// void run_tests() {
//     char *test_data[] = {"10", "-5", "20", "30", NULL}; // Datos de prueba
//     t_stack *stack = NULL;

//     // Prueba de Casos Normales
//     printf("Prueba de Casos Normales:\n");
//     stack = transfer_stack(test_data[0], NULL);
//     for (int i = 1; test_data[i] != NULL; i++) {
//         stack = transfer_stack(test_data[i], stack);
//     }
//     print_stack(stack, NULL);
//     free_stack(&stack);

//     // Prueba de Datos Vacíos
//     printf("Prueba de Datos Vacíos:\n");
//     char *empty_data[] = {NULL}; // Datos vacíos
//     stack = transfer_stack(empty_data[0], NULL);
//     print_stack(stack, NULL);
//     free_stack(&stack);

//     // Prueba de Datos Numéricos Inválidos
//     printf("Prueba de Datos Numéricos Inválidos:\n");
//     char *invalid_data[] = {"10", "abc", "20", NULL}; // Datos con valor no numérico
//     stack = transfer_stack(invalid_data[0], NULL);
//     for (int i = 1; invalid_data[i] != NULL; i++) {
//         stack = transfer_stack(invalid_data[i], stack);
//     }
//     print_stack(stack, NULL);
//     free_stack(&stack);

//     // Prueba de Números Fuera de Rango
//     printf("Prueba de Números Fuera de Rango:\n");
//     char *out_of_range_data[] = {"10", "2147483648", "20", NULL}; // Datos con valor fuera de rango
//     stack = transfer_stack(out_of_range_data[0], NULL);
//     for (int i = 1; out_of_range_data[i] != NULL; i++) {
//         stack = transfer_stack(out_of_range_data[i], stack);
//     }
//     print_stack(stack, NULL);
//     free_stack(&stack);
// }
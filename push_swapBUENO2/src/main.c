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

/* Se encarga de manejar el algoritmo que se aplica a dos pilas (stack_a y stack_b).
 Primero, asigna índices a los elementos de la pila stack_a y luego, si la pila stack_a
  no está ordenada, aplica el mejor algoritmo para ordenarla. */
void	handle_algorithm(t_stack **stack_a, t_stack **stack_b, int size)
{
	put_index(*stack_a, size + 1);
	if (!list_sorted(stack_a))
		best_algorit(stack_a, stack_b, stack_size(*stack_a));
}
/* Verifica los argumentos de entrada (argv) y los agrega a la pila stack_a.
Después de agregar todos los argumentos a la pila, llama a la función handle_algorithm
para ordenar la pila. Finalmente, libera la memoria ocupada por las pilas antes
de terminar el programa. */
int	main(int argc, char **argv)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;
	int size;
	int i;

	i = 1;
	size = stack_size(stack_a);
	while (i < argc)
	{
		check_argv(argv[i], &stack_a);
		i++;
		printf("entró\n");
	}
	if(check_dupli(stack_a))
		error_exit(&stack_a, NULL);
	handle_algorithm(&stack_a, &stack_b, size);
/* 	free_stack(&stack_a);
	free_stack(&stack_b); */
	return (0);
}

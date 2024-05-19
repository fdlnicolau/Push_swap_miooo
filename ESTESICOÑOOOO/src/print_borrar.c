/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_borrar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:52:38 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/07 15:45:46 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_stack(t_stack* stack_a, t_stack* stack_b)
  {
     t_stack* current_node;
     printf("Stack A: ");
     current_node = stack_a;
	 
     while (current_node != NULL) {
         printf("%ld ", current_node->value);
         current_node = current_node->next;
     }
     printf("\n");

     printf("Stack B: ");
     current_node = stack_b;
     while (current_node != NULL) {
         printf("%ld ", current_node->value);
         current_node = current_node->next;
     }
     printf("\n");
  }

  #include <stdio.h>

void printValuesAndIndices(t_stack *head) 
{
	//ft_printf("\ntomalacasito\n");
	//write(1, "hola\n", 5);
    t_stack *current = head;

    while (current != NULL) {
        //printf("Value: %ld, Index: %d\n", current->value, current->index);
        current = current->next;
    }
}

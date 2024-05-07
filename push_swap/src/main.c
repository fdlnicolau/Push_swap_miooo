/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:16:53 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/06 23:46:10 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//me comprueba que sea un numero


void handle_stack(char **str, t_stack **stack_a)
{
    int i = 0;

    *stack_a = transfer_stack(str[i], NULL);
    if (*stack_a == NULL)
    {
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
	}
    while (str[++i] != NULL)
    {
        *stack_a = transfer_stack(str[i], *stack_a);
        if (*stack_a == NULL)
        {
            ft_printf("Error\n");
            exit(EXIT_FAILURE);
        }
    }
}

void handle_algorithm(t_stack **stack_a, t_stack **stack_b)
{
    if (!list_sorted(stack_a)) 
        best_algorit(stack_a, stack_b, stack_size(*stack_a));
}

int	main(int argc, char **argv)
{
    t_stack		*stack_a = NULL;
    t_stack 	*stack_b = NULL;
    char 		**str;

    str = check_argv(argc, argv);
    handle_stack(str, &stack_a);
    print_stack(stack_a, NULL);
    handle_algorithm(&stack_a, &stack_b);
    if (argc == 2)
        free_str(str);
    print_stack(stack_a, NULL);
    return(free_stack(&stack_a), free_stack(&stack_b), 0);
}
/* int is_valid_number(char *str)
{
	int i;

	i = 0;
	if(str[i] == '\0')
		return(0);
	if ((str[i] == '+' || str[i] == '-') && (is_valid_number(&str[i + 1])))
        i++;
	while(str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
        	i++;
		else if (str[i] == '\0')
			return(1);
		else
			return(0);
			
		if (ft_atoi(str[i]) < -2147483648 || ft_atoi(argv[i]) > 2147483647)
			return (0);
	}
	return (1);
}

int find_max_index(int *numbers, int start, int end)
{
	int i;
	int max_index = start;
	
	i = start + 1;
	while (i <= end)
	{
		if(numbers[i] > numbers[max_index])
			max_index = i;
		i++;
	}
	printf("%d\n\n", numbers[max_index]);
	return max_index;
	
}

void rotate_left(int *number, int num_count)
{
    int i;
    int temp;
    temp = number[0];
    i = 0;

    while(i < num_count - 1)
    {
        number[i] = number[i + 1];
        i++;
    }
    number[num_count - 1] = temp;
}

void rotate_right(int *number, int num_count)
{
    int i;
    int temp;
    temp = number[num_count - 1];
    i = num_count - 1;

    while(i > 0)
    {
        number[i] = number[i - 1];
        i--;
    }
    number[0] = temp;
}

int main (int argc, char **argv)
{
	int i;
	int j;
	int *number;
	int max_index;
	int k;
	i = 1;
	j = 0;
	if (argc == 1)
		return(0);
	if(argc >= 2)
	{
		while(argv[i])
		{
			if(is_valid_number(argv[i]) == 0)
			{
				write(2,"Error\n",6);
				exit(1);
			}
			i++;
		}
		i = 1;
		number = (int *)malloc(sizeof(int) * argc);
		while (i < argc)
		{
			if (is_valid_number(argv[i]) == 0)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			number[j] = atoi(argv[i]);
			i++;
			j++;
		}
		i = 0;
		while (i < j)
		{
			k = i + 1;
			while (k < j)
			{
				if (number[i] == number[k])
				{
					write(2,"Error\n",6);
					exit(1);
				}
				k++;
			}
			i++;
		}
		i = 0;
		j = 0;
		while (j < argc - 1) 
		{
			j++;
		}
		max_index = find_max_index(number, 0, j - 1);
		while(max_index != j - 1)
		{
			if (max_index < j / 2)
			{
				rotate_left(number, j);
				max_index++;
			}
		}
		    i = 0;
    	while (i < j)
    	{
        	printf("%d\n", number[i]);
        	i++;
    	}
		free(number);
	}
	return(0);
} */











	
	/* if(argc >= 4)
	{
		printf( "%s", "suficientes argumentos");
		//inicializa las cabezas de las listas
		t_node *head1 = NULL;
		t_node *head2 = NULL;
		t_node *new_node;

		//Crea la primera lista enlazada
		while(i < argc)
		{
			//Crea un nuevo nudo
			new_node = malloc(sizeof(t_node));
			
		    if(!is_valid_number(argv[i])) 
			{ // Si el argumento no es un número válido
        		printf("Esto no es un numero\n");
        		return(1);
   			}
			 
			new_node->number = atoi(argv[i]);//Almacena el numero del nudo
        	new_node->next = head1; // Enlaza el nuevo nodo con la lista
        	head1 = new_node; // Actualiza la cabeza de la lista

        	i++;
			
		}
		while(i < argc)
		{
			t_node *new_node = malloc(sizeof(t_node));
			new_node->number = atoi(argv[i]);
			new_node->next = head2;
			head2 = new_node;
			if(new_node->number == 0 && argv[i][0] != '0')
			{
				printf("Esto no es un numero\n");
				return(1);
			}
			i++;
			
		}
		
	}
	return(0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:16:53 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/03 17:41:41 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	init_program(t_stack ***stack_a, t_stack ***stack_b)
// {
// 	*stack_a = malloc(sizeof(t_stack *));
// 	if(*stack_a == NULL)
// 	{
// 		ft_printf("Error\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	**stack_a = NULL;
// 	*stack_b = malloc(sizeof(t_stack *));
// 	if(*stack_b == NULL)
// 	{
// 		ft_printf("Error\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	**stack_b = NULL;
// }
int is_valid_number (char **str)
{
	int i;
	int j;
	
	i =	0;
	j = 0;
	if(str[i] == NULL)
		return(FALSE);
	while (str[i] != NULL)
	{
		j = 0;
		if ((str[i][j] == '+' || str[i][j] == '-')) 
			j++;
		while (str[i][j] != 0 && (str[i][j] <= '9' && str[i][j] >= '0'))
		{
			j++;
		}
		if (str[i][j] == '\0')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_dupli(char **str)
{
	int i = 0;
	int j;

	while (str[i] != NULL)
	{
		j = i + 1;
		while (str[j] != NULL)
		{
			if (ft_strncmp(str[i], str[j], 15) == 0)//CERDADA!!!! YEAH
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
void check_all (char **str)
{
	if(check_dupli(str) == FALSE)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	if (is_valid_number((str)) == FALSE)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
char **check_argv(int argc, char **argv)
{
	char **str;
	if(argc < 2)
		exit(EXIT_FAILURE);
	else if(argc == 2)
	{
		str = ft_split(argv[1], ' ');
		if(str == NULL)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		check_all(str);
		return(str);
	}
	else
	{
		check_all(argv + 1);
		return(argv + 1);
	}
}

long	ft_atol(const char *str)
{
	long	digit;
	int		i;
	int		sig;

	i = 0;
	digit = 0;
	sig = 1;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sig *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = (digit * 10) + (str[i] - '0');
		i++;
	}
	return (digit * sig);
}

t_stack*	transfer_stack(char *string_value, t_stack *ptr_stack)
{
	t_stack 	*current;
	t_stack 	*new_node;
	long 		value;
	
	value = ft_atol(string_value);
	if (value < -2147483648 || value > 2147483647)
			return (NULL);
	new_node = malloc(sizeof(t_stack*));
	if(new_node == NULL)
		return(NULL);
	new_node->value = value;
	new_node->next = NULL;

	if(ptr_stack == NULL)
		ptr_stack = new_node;
	else
	{
		current = ptr_stack;
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
	}
	return(ptr_stack);
}
int main (int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack 	**stack_b = NULL;
	char 		**str;
	int 		i;

	i = 0;
	// init_program(&stack_a, &stack_b);
	str = check_argv(argc, argv);
	stack_a = transfer_stack(str[i], NULL);
	if(stack_a == NULL)
		exit(EXIT_FAILURE);
	while(str[++i] != NULL)
	{
		stack_a = transfer_stack(str[i], stack_a);
		if(stack_a == FALSE)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
	}
	print_stack(stack_a, NULL);
	if(!list_sorted(&stack_a)) 
	{
		best_algorit(&stack_a, stack_b, stack_size(stack_a));
	}
	print_stack(stack_a, NULL);
	return(0);
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
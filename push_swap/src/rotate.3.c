/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:43:17 by lnicolau          #+#    #+#             */
/*   Updated: 2024/05/06 23:43:50 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate_r(t_stack **stack_a, t_stack **stack_b, int flag)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (flag == 1)
		ft_printf("rrr\n");
}
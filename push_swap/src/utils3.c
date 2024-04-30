/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolau <lnicolau@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:27:36 by lnicolau          #+#    #+#             */
/*   Updated: 2024/04/30 16:36:20 by lnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void calculate_near(t_stack *copy_a, t_stack *copy_b, int *rest)
{
	while(copy_a)
	{
		if(copy_b->index < copy_a->index)
		{
			if(copy_a->index - copy_b->index <= *rest)
			{
				*rest = copy_a->index - copy_b->index;
				copy_b->target = copy_a->pos;
			}
		}
		copy_a = copy_a->next
	}
}
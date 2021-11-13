/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:20:37 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 16:52:23 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *stack)
{
	int	i;

	i = -1;
	while (++i < 2 && !is_ordered(stack->a, stack->size_a))
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
		else if (stack->a[stack->size_a - 2] > stack->a[stack->size_a - 1]
			|| stack->a[0] > stack->a[stack->size_a - 1])
			rev_rotate_a(stack);
	}
}

void	minisort(t_stacks *stack)
{
	int	pos;

	while (stack->size_a > 3)
		push_b(stack);
	sort_three(stack);
	while (stack->size_b > 0)
	{
		pos = find_position(stack->b[0], stack);
		if (pos == 0)
			push_a(stack);
		else if (pos < stack->size_a - pos)
			rotate_a(stack);
		else
			rev_rotate_a(stack);
	}
	while (!is_sorted(stack) && !use_rev_rotation(stack))
		rotate_a(stack);
	while (!is_sorted(stack) && use_rev_rotation(stack))
		rev_rotate_a(stack);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:56:29 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 18:30:25 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	sort_three(t_stacks *stack)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 2 && !is_ordered(stack->a, stack->size_a))
// 	{
// 		if (stack->a[0] > stack->a[1])
// 			swap_a(stack);
// 		else if (stack->a[stack->size_a - 2] > stack->a[stack->size_a - 1]
// 			|| stack->a[0] > stack->a[stack->size_a - 1])
// 			rev_rotate_a(stack);
// 	}
// }

static void	fill_b(int *markup, t_stacks *stack)
{
	int	i;
	int	size;

	i = -1;
	size = stack->size_a;
	while (++i < size)
	{
		if (markup[i])
			rotate_a(stack);
		else
			push_b(stack);
	}
	free(markup);
}

void	bigsort(t_stacks *stack)
{
	int	*markup;
	int	pos_a;

	display_stacks(stack);
	markup = best_markup_a(stack);
	display_markup(markup, stack);
	fill_b(markup, stack);
	display_stacks(stack);
	while (stack->size_b > 0)
	{
		pos_a = find_position(stack->b[0], stack);
		if (pos_a == 0)
			push_a(stack);
		else if (pos_a < stack->size_a - pos_a)
			rotate_a(stack);
		else
			rev_rotate_a(stack);
	}
	display_stacks(stack);
	while (!is_sorted(stack) && !use_rev_rotation(stack))
		rotate_a(stack);
	while (!is_sorted(stack) && use_rev_rotation(stack))
		rev_rotate_a(stack);
	display_stacks(stack);
}

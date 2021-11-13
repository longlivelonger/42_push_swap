/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:56:29 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 20:35:39 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	*markup_b(t_stacks *stack)
{
	int	i;
	int	pos;
	int	*markup;

	markup = malloc(stack->size_b * sizeof(*markup));
	if (markup == 0)
		return (0);
	i = -1;
	while (++i < stack->size_b)
	{
		if (i < stack->size_b / 2)
			markup[i] = i;
		else
			markup[i] = stack->size_b - i;
		pos = find_position(stack->b[i], stack);
		if (pos > stack->size_a / 2)
			pos = stack->size_a - pos;
		markup[i] += pos;
	}
	return (markup);
}

static int	find_min_index(int *stack, int size)
{
	int	i;
	int	best_i;
	int	best_score;
	int	min;

	min = find_min(stack, size);
	i = index_elem(min, stack, size);
	best_i = i;
	best_score = i;
	while (++i < size)
	{
		if (stack[i] == min && size - i < best_score)
		{
			best_i = i;
			best_score = size - i;
		}
	}
	return (best_i);
}

void	bigsort(t_stacks *stack, int *markup)
{
	int	pos_a;
	int	pos_b;

	fill_b(best_markup_a(stack), stack);
	while (stack->size_b > 0)
	{
		markup = markup_b(stack);
		pos_b = find_min_index(markup, stack->size_b);
		pos_a = find_position(stack->b[pos_b], stack);
		if (pos_a == 0 && pos_b == 0)
			push_a(stack);
		if (pos_a != 0 && pos_a < stack->size_a - pos_a)
			rotate_a(stack);
		else if (pos_a != 0)
			rev_rotate_a(stack);
		if (pos_b != 0 && pos_b < stack->size_b - pos_b)
			rotate_b(stack);
		else if (pos_b != 0)
			rev_rotate_b(stack);
		free(markup);
	}
	while (!is_sorted(stack) && !use_rev_rotation(stack))
		rotate_a(stack);
	while (!is_sorted(stack) && use_rev_rotation(stack))
		rev_rotate_a(stack);
}

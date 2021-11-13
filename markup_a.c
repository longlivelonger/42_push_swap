/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:13:33 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 20:26:39 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*malloc_markup(int size, int head)
{
	int	*markup;

	markup = malloc(size * sizeof(*markup));
	if (markup == 0)
		return (0);
	markup[head] = 1;
	return (markup);
}

static int	keep_in_stack_a(int i, int last, int head, t_stacks *stack)
{
	int	result;
	int	after_max;
	int	max;
	int	max_index;

	max = find_max(stack->a, stack->size_a);
	max_index = index_elem(max, stack->a, stack->size_a);
	if (head < i)
	{
		after_max = (int)(max_index < i);
		result = (int)((last < stack->a[i] && !after_max)
				|| (last == stack->size_a - 1
					&& stack->a[i] < stack->a[head]));
	}
	else
	{
		after_max = (int)(max_index < i || max_index > head);
		result = (int)((last < stack->a[i] && !after_max
					&& stack->a[i] < stack->a[head])
				|| (last == stack->size_a - 1 && stack->a[i] < stack->a[head]));
	}
	return (result);
}

static int	*markup_a(int head, t_stacks *stack)
{
	int	i;
	int	last;
	int	*markup;

	markup = malloc_markup(stack->size_a, head);
	if (markup == 0)
		return (0);
	i = head;
	last = stack->a[head];
	while (++i < stack->size_a)
	{
		markup[i] = keep_in_stack_a(i, last, head, stack);
		if (markup[i])
			last = stack->a[i];
	}
	i = -1;
	while (++i < head)
	{
		markup[i] = keep_in_stack_a(i, last, head, stack);
		if (markup[i])
			last = stack->a[i];
	}
	return (markup);
}

static int	sum_array(int *arr, int size)
{
	int	i;
	int	sum;

	sum = 0;
	i = -1;
	while (++i < size)
		sum += arr[i];
	return (sum);
}

int	*best_markup_a(t_stacks *stack)
{
	int	i;
	int	sum;
	int	best_head;
	int	best_sum;
	int	*markup;

	best_head = -1;
	best_sum = -1;
	i = -1;
	while (++i < stack->size_a)
	{
		markup = markup_a(i, stack);
		sum = sum_array(markup, stack->size_a);
		if (best_head == -1 || sum > best_sum)
		{
			best_head = i;
			best_sum = sum;
		}
		free(markup);
	}
	return (markup_a(best_head, stack));
}

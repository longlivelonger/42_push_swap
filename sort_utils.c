/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:51:03 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 16:52:50 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(int *stack, int size)
{
	int	i;
	int	min;
	int	max;

	min = find_min(stack, size);
	max = find_max(stack, size);
	i = -1;
	while (++i < size - 1)
	{
		if (stack[i] != max && stack[i] < stack[i + 1])
			continue ;
		if (stack[i] == max && stack[i + 1] == min)
			continue ;
		else
			return (0);
	}
	return (1);
}

int	index_elem(int elem, int *stack, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		if (elem == stack[i])
			return (i);
	return (-1);
}

int	use_rev_rotation(t_stacks *stack)
{
	if (index_elem(0, stack->a, stack->size_a) > stack->size_a / 2)
		return (1);
	return (0);
}

int	find_position(int elem, t_stacks *stack)
{
	int	i;
	int	min;
	int	max;

	min = find_min(stack->a, stack->size_a);
	max = find_max(stack->a, stack->size_a);
	if (elem < min)
		i = index_elem(min, stack->a, stack->size_a);
	if (elem > max)
		i = index_elem(max, stack->a, stack->size_a) + 1;
	if (elem < min || elem > max)
	{
		if (i == stack->size_a)
			i = 0;
		return (i);
	}
	if (stack->a[stack->size_a - 1] < elem && elem < stack->a[0])
		return (0);
	i = 0;
	while (++i < stack->size_a)
		if (stack->a[i - 1] < elem && elem < stack->a[i])
			return (i);
	return (-1);
}

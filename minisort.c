/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:20:37 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 21:43:35 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stacks *stacks, int sort_a)
{
	int	i;

	i = -1;
	if (sort_a)
	{
		while (++i < 2)
		{
			if (stacks->a[stacks->size_a - 2] > stacks->a[stacks->size_a - 1]
				|| stacks->a[0] > stacks->a[stacks->size_a - 1])
				rev_rotate_a(stacks);
			else if (stacks->a[0] > stacks->a[1])
				swap_a(stacks);
		}
	}
	else
	{
		while (++i < 2)
		{
			if (stacks->b[stacks->size_b - 2] < stacks->b[stacks->size_b - 1]
				|| stacks->b[0] < stacks->b[stacks->size_b - 1])
				rev_rotate_b(stacks);
			else if (stacks->b[0] < stacks->b[1])
				swap_b(stacks);
		}
	}
}

int	find_max(int *stack, int size)
{
	int	i;
	int	max;

	max = stack[0];
	i = 0;
	while (++i < size)
		if (max < stack[i])
			max = stack[i];
	return (max);
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

int	use_rev_rotation(t_stacks *stacks)
{
	if (index_elem(0, stacks->a, stacks->size_a) > stacks->size_a / 2)
		return (1);
	return (0);
}

void	minisort(t_stacks *stacks)
{
	int	max;

	while (stacks->size_a > 3)
		push_b(stacks);
	sort_three(stacks, 1);
	if (stacks->size_b > 0)
		sort_three(stacks, 0);
	while (stacks->size_b > 0)
	{
		max = find_max(stacks->a, stacks->size_a);
		if (stacks->b[0] == stacks->a[0] - 1
			|| stacks->b[0] == stacks->a[stacks->size_a - 1] + 1
			|| (stacks->b[0] > max && stacks->a[stacks->size_a - 1] == max))
			push_a(stacks);
		else
			rotate_a(stacks);
	}
	if (!is_sequential(stacks))
	{
		write(1, "not_sequential\n", 15);
		return ;
	}
	while (!is_sorted(stacks) && !use_rev_rotation(stacks))
		rotate_a(stacks);
	while (!is_sorted(stacks) && use_rev_rotation(stacks))
		rev_rotate_a(stacks);
}

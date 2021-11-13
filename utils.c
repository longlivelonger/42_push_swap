/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:04:20 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 16:15:54 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b > 0)
		return (0);
	i = -1;
	while (++i < stacks->size_a)
		if (stacks->a[i] != i)
			return (0);
	return (1);
}

int	is_sequential(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b > 0)
		return (0);
	i = -1;
	while (++i < stacks->size_a - 1)
		if (stacks->a[i] != stacks->a[i + 1] - 1)
			break ;
	if (stacks->a[i] == stacks->size_a - 1 && stacks->a[i + 1] == 0)
	{
		while (++i < stacks->size_a - 1)
			if (stacks->a[i] != stacks->a[i + 1] - 1)
				break ;
		if (i < stacks->size_a - 1)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	find_min(int *stack, int size)
{
	int	i;
	int	min;

	min = stack[0];
	i = 0;
	while (++i < size)
		if (min > stack[i])
			min = stack[i];
	return (min);
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

void	append_operation(t_ops operation, t_stacks *stack)
{
	int		i;
	t_ops	*temp;

	temp = malloc((stack->size_ops + 1) * sizeof(*temp));
	if (temp == 0)
		return ;
	temp[stack->size_ops] = operation;
	if (stack->ops != 0)
	{
		i = -1;
		while (++i < stack->size_ops)
			temp[i] = stack->ops[i];
		free(stack->ops);
	}
	stack->ops = temp;
	stack->size_ops++;
}

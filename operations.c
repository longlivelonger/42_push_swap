/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:23:55 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 18:11:12 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->size_a)
		stacks->a[stacks->size_a - i] = stacks->a[stacks->size_a - i - 1];
	stacks->a[0] = stacks->b[0];
	stacks->size_b--;
	stacks->size_a++;
	i = -1;
	while (++i < stacks->size_b)
		stacks->b[i] = stacks->b[i + 1];
	write(1, "pa\n", 3);
}

void	push_b(t_stacks *stacks)
{
	int	i;

	i = -1;
	while (++i < stacks->size_b)
		stacks->b[stacks->size_b - i] = stacks->b[stacks->size_b - i - 1];
	stacks->b[0] = stacks->a[0];
	stacks->size_a--;
	stacks->size_b++;
	i = -1;
	while (++i < stacks->size_a)
		stacks->a[i] = stacks->a[i + 1];
	write(1, "pb\n", 3);
}

void	swap_a(t_stacks *stack)
{
	int	temp;

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stacks *stack)
{
	int	temp;

	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	write(1, "sb\n", 3);
}

void	rev_rotate_a(t_stacks *stacks)
{
	int	i;
	int	temp;

	temp = stacks->a[stacks->size_a - 1];
	i = -1;
	while (++i < stacks->size_a - 1)
		stacks->a[stacks->size_a - i - 1] = stacks->a[stacks->size_a - i - 2];
	stacks->a[0] = temp;
	write(1, "rra\n", 4);
}

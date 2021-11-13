/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:23:55 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 20:12:08 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_a)
		stack->a[stack->size_a - i] = stack->a[stack->size_a - i - 1];
	stack->a[0] = stack->b[0];
	stack->size_b--;
	stack->size_a++;
	i = -1;
	while (++i < stack->size_b)
		stack->b[i] = stack->b[i + 1];
	append_operation(pa, stack);
}

void	push_b(t_stacks *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_b)
		stack->b[stack->size_b - i] = stack->b[stack->size_b - i - 1];
	stack->b[0] = stack->a[0];
	stack->size_a--;
	stack->size_b++;
	i = -1;
	while (++i < stack->size_a)
		stack->a[i] = stack->a[i + 1];
	append_operation(pb, stack);
}

void	swap_a(t_stacks *stack)
{
	int	temp;

	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	append_operation(sa, stack);
}

void	swap_b(t_stacks *stack)
{
	int	temp;

	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	append_operation(sb, stack);
}

void	rev_rotate_a(t_stacks *stack)
{
	int	i;
	int	temp;

	temp = stack->a[stack->size_a - 1];
	i = -1;
	while (++i < stack->size_a - 1)
		stack->a[stack->size_a - i - 1] = stack->a[stack->size_a - i - 2];
	stack->a[0] = temp;
	append_operation(rra, stack);
}

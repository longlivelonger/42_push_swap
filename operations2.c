/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:59:19 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 20:12:19 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_b(t_stacks *stack)
{
	int	i;
	int	temp;

	temp = stack->b[stack->size_b - 1];
	i = -1;
	while (++i < stack->size_b - 1)
		stack->b[stack->size_b - i - 1] = stack->b[stack->size_b - i - 2];
	stack->b[0] = temp;
	append_operation(rrb, stack);
}

void	rotate_a(t_stacks *stack)
{
	int	i;
	int	temp;

	temp = stack->a[0];
	i = -1;
	while (++i < stack->size_a - 1)
		stack->a[i] = stack->a[i + 1];
	stack->a[i] = temp;
	append_operation(ra, stack);
}

void	rotate_b(t_stacks *stack)
{
	int	i;
	int	temp;

	temp = stack->b[0];
	i = -1;
	while (++i < stack->size_b - 1)
		stack->b[i] = stack->b[i + 1];
	stack->b[i] = temp;
	append_operation(rb, stack);
}

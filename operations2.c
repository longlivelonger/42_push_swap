/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:59:19 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 18:24:52 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_b(t_stacks *stacks)
{
	int	i;
	int	temp;

	temp = stacks->b[stacks->size_b - 1];
	i = -1;
	while (++i < stacks->size_b - 1)
		stacks->b[stacks->size_b - i - 1] = stacks->b[stacks->size_b - i - 2];
	stacks->b[0] = temp;
	write(1, "rrb\n", 4);
}

void	rotate_a(t_stacks *stacks)
{
	int	i;
	int	temp;

	temp = stacks->a[0];
	i = -1;
	while (++i < stacks->size_a - 1)
		stacks->a[i] = stacks->a[i + 1];
	stacks->a[i] = temp;
	write(1, "ra\n", 3);
}

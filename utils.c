/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:04:20 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 17:10:38 by sbronwyn         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:32:53 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 17:05:23 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(const char *str)
{
	int	num;
	int	i;
	int	minus;

	minus = 0;
	num = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus = 1;
	i--;
	while (str[++i] >= '0' && str[i] <= '9')
	{
		if (num * 10 < 0 && minus)
			return (0);
		if (num * 10 < 0)
			return (-1);
		num = num * 10 + str[i] - '0';
	}
	if (minus)
		return (-num);
	return (num);
}

t_stacks	*create_stacks(int size, char **numbers)
{
	t_stacks	*stacks;
	int			i;

	stacks = malloc(sizeof(*stacks));
	if (stacks == 0)
		return (0);
	stacks->size_a = size;
	stacks->size_b = 0;
	stacks->a = malloc(size * sizeof(stacks->a));
	if (stacks->a == 0)
		return (0);
	stacks->b = malloc(size * sizeof(stacks->b));
	if (stacks->b == 0)
		return (0);
	i = -1;
	while (++i < size)
		stacks->a[i] = ft_atoi(numbers[i + 1]);
	return (stacks);
}

static void	sort_input(int *stack, int *seq, int size)
{
	int	i;
	int	sorted;
	int	temp;

	sorted = 0;
	while (sorted == 0)
	{
		sorted = 1;
		i = -1;
		while (++i < size - 1)
		{
			if (stack[i] > stack[i + 1])
			{
				sorted = 0;
				temp = stack[i];
				stack[i] = stack[i + 1];
				stack[i + 1] = temp;
				temp = seq[i];
				seq[i] = seq[i + 1];
				seq[i + 1] = temp;
			}
		}
	}
}

void	order_input(t_stacks *stacks)
{
	int	*seq;
	int	i;

	seq = malloc(stacks->size_a * sizeof(*seq));
	if (seq == 0)
		return ;
	i = -1;
	while (++i < stacks->size_a)
		seq[i] = i;
	sort_input(stacks->a, seq, stacks->size_a);
	i = -1;
	while (++i < stacks->size_a)
		stacks->a[seq[i]] = i;
	free(seq);
}

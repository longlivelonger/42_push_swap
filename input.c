/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:32:53 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 21:05:52 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	ft_atoi(const char *str)
{
	long int	num;
	int			i;
	int			minus;

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
		num = num * 10 + str[i] - '0';
		if ((minus && - num < INT_MIN) || (!minus && num > INT_MAX))
			exit(display_error());
	}
	if (minus)
		return ((int)(-num));
	if (str[i] != '\0')
		exit(display_error());
	return ((int)(num));
}

t_stacks	*create_stacks(int size, char **numbers)
{
	t_stacks	*stack;
	int			i;

	stack = malloc(sizeof(*stack));
	if (stack == 0)
		return (0);
	stack->ops = 0;
	stack->size_ops = 0;
	stack->size_a = size;
	stack->size_b = 0;
	stack->a = malloc(size * sizeof(stack->a));
	if (stack->a == 0)
		return (0);
	stack->b = malloc(size * sizeof(stack->b));
	if (stack->b == 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		if (numbers[i + 1][0] == '\0')
			exit(display_error());
		stack->a[i] = ft_atoi(numbers[i + 1]);
	}
	return (stack);
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

void	order_input(t_stacks *stack)
{
	int	*seq;
	int	i;

	seq = malloc(stack->size_a * sizeof(*seq));
	if (seq == 0)
		return ;
	i = -1;
	while (++i < stack->size_a)
		seq[i] = i;
	sort_input(stack->a, seq, stack->size_a);
	i = -1;
	while (++i < stack->size_a)
		stack->a[seq[i]] = i;
	free(seq);
}

int	has_duplicates(t_stacks *stack)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size_a)
	{
		j = i;
		while (++j < stack->size_a)
			if (stack->a[i] == stack->a[j])
				return (1);
	}
	return (0);
}

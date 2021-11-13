/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:28:00 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 20:34:04 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_operations_part2(int i, t_stacks *stack)
{
	if (i < stack->size_ops - 1
		&& ((stack->ops[i] == ra && stack->ops[i + 1] == rb)
			|| (stack->ops[i] == rb && stack->ops[i + 1] == ra)))
	{
		write(1, "rr\n", 3);
		stack->ops[i + 1] = skip;
	}
	else if (stack->ops[i] == ra)
		write(1, "ra\n", 3);
	else if (stack->ops[i] == rb)
		write(1, "rb\n", 3);
	else if (i < stack->size_ops - 1
		&& ((stack->ops[i] == rra && stack->ops[i + 1] == rrb)
			|| (stack->ops[i] == rrb && stack->ops[i + 1] == rra)))
	{
		write(1, "rrr\n", 4);
		stack->ops[i + 1] = skip;
	}
	else if (stack->ops[i] == rra)
		write(1, "rra\n", 4);
	else if (stack->ops[i] == rrb)
		write(1, "rrb\n", 4);
}

void	print_operations(t_stacks *stack)
{
	int	i;

	i = -1;
	while (++i < stack->size_ops)
	{
		if (stack->ops[i] == pa)
			write(1, "pa\n", 3);
		else if (stack->ops[i] == pb)
			write(1, "pb\n", 3);
		else if (stack->ops[i] == sa)
			write(1, "sa\n", 3);
		else if (stack->ops[i] == sb)
			write(1, "sb\n", 3);
		else if (stack->ops[i] == ra || stack->ops[i] == rb
			|| stack->ops[i] == rra || stack->ops[i] == rrb)
			print_operations_part2(i, stack);
	}
}

int	main(int argc, char **argv)
{
	t_stacks	*stack;

	if (argc <= 1)
		return (EXIT_FAILURE);
	stack = create_stacks(argc - 1, argv);
	if (has_duplicates(stack))
		return (EXIT_FAILURE);
	order_input(stack);
	if (is_sorted(stack))
		return (EXIT_SUCCESS);
	if (argc - 1 <= 5)
		minisort(stack);
	else
		bigsort(stack, 0);
	print_operations(stack);
	free(stack->a);
	free(stack->b);
	free(stack->ops);
	free(stack);
	return (EXIT_SUCCESS);
}

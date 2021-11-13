/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:28:00 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 16:57:45 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		bigsort(stack);
	return (EXIT_SUCCESS);
}

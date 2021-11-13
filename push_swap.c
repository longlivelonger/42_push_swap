/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:28:00 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 17:22:13 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc <= 1)
		return (EXIT_FAILURE);
	stacks = create_stacks(argc - 1, argv);
	order_input(stacks);
	if (is_sorted(stacks))
		return (EXIT_SUCCESS);
	if (argc - 1 <= 5)
		minisort(stacks);
	return (EXIT_SUCCESS);
}

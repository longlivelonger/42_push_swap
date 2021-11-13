/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:28:00 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/09 19:11:35 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

t_stacks	*create_stacks(int size, char **numbers);
void		order_input(t_stacks *stacks);

int			is_sorted(t_stacks *stacks);
int			is_sequential(t_stacks *stacks);

void		minisort(t_stacks *stack);

void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		swap_a(t_stacks *stack);
void		swap_b(t_stacks *stack);
void		rev_rotate_a(t_stacks *stacks);

void		rev_rotate_b(t_stacks *stacks);
void		rotate_a(t_stacks *stacks);

#endif
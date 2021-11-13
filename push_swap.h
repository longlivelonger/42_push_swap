/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbronwyn <sbronwyn@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 14:28:00 by sbronwyn          #+#    #+#             */
/*   Updated: 2021/11/13 20:34:00 by sbronwyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef enum e_ops
{
	skip,
	pa,
	pb,
	sa,
	sb,
	rra,
	rrb,
	ra,
	rb
}	t_ops;

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	t_ops	*ops;
	int		size_ops;
}	t_stacks;

t_stacks	*create_stacks(int size, char **numbers);
void		order_input(t_stacks *stack);
int			has_duplicates(t_stacks *stack);

int			is_sorted(t_stacks *stacks);
int			is_sequential(t_stacks *stacks);
int			find_min(int *stack, int size);
int			find_max(int *stack, int size);
void		append_operation(t_ops operation, t_stacks *stack);

int			is_ordered(int *stack, int size);
int			index_elem(int elem, int *stack, int size);
int			use_rev_rotation(t_stacks *stack);
int			find_position(int elem, t_stacks *stack);

int			*best_markup_a(t_stacks *stack);

void		minisort(t_stacks *stack);
void		bigsort(t_stacks *stack, int *markup);

void		push_a(t_stacks *stack);
void		push_b(t_stacks *stack);
void		swap_a(t_stacks *stack);
void		swap_b(t_stacks *stack);
void		rev_rotate_a(t_stacks *stack);

void		rev_rotate_b(t_stacks *stack);
void		rotate_a(t_stacks *stack);
void		rotate_b(t_stacks *stack);

#endif
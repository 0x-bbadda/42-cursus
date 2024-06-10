/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:22:23 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 00:15:30 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*prev;
	int				content;
	struct s_list	*next;
}t_list;

typedef struct s_index
{
	int		i;
	int		j;
}t_index;

// --------------------------simple_helper_functions-----------------//
int				__atoi(char *s, t_list *stack_a);
int				is_instack(t_list *stack_t_a, int content);
void			ft_error(t_list **stack_a);
void			__check_if_empty(char *s, t_list **stack_a);
int				__is_sorted(t_list *stack_a);
// -------------------------linked_list_functions-------------------//
t_list			*__new_d_list(int content);
void			__create_list(t_list **stack_t_a, int content);
t_list			*__last_node(t_list *stack_a);
int				__lstsize(t_list *lst);
t_list			*__duplicat_node(t_list *stack_a);
void			free_stack(t_list **stack);
void			__free(char **str, int j);
// ------------------------intsruction_rules_functions--------------//
void			__push(t_list **stack_a, t_list **stack_b);
void			sa(t_list *stack_a, t_list *tmp);
void			sb(t_list *stack_b, t_list *tmp);
void			pa(t_list **stack_a, t_list **stack_b);
t_list			*pb(t_list **stack_a, t_list **stack_b);
void			ra(t_list **stack_a);
t_list			*rb(t_list **stack_b);
void			rr(t_list **stack_a, t_list **stack_b);
void			rra(t_list **stack_a);
void			rrb(t_list **stack_b);
void			rrr(t_list **stack_a, t_list **stack_b);
// -------------------------sorting_functions-----------------------//
void			__simple_sort(t_list **stack_a, t_list **stack_b, int lenth);
void			__2_num_case(t_list *stack_a);
void			__3_num_case(t_list **stack_a);
void			__4_num_case(t_list **stack_a, t_list **stack_b);
void			__5_num_case(t_list **stack_a, t_list **stack_b);
void			__range(t_list **stack_a, t_list **stack_b);
// --------------------------get_helper_functions-------------------//
int				get_min_num(t_list **stack_a);
void			get_min_top(t_list **stack_a, int min);
void			get_max_top(t_list **stack_b, int max);
t_list			*get_sorted_stack(t_list *stack_a);
t_list			*get_indexed_stack(t_list *stack_a, t_list *__new_d_list);

#endif
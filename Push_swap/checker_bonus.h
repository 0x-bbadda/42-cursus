/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:21:50 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 01:41:09 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	struct s_node	*prev;
	int				content;
	struct s_node	*next;
}t_node;

typedef struct s_index
{
	int		i;
	int		j;
	int		lenth;
}t_index;

// ------------------simple_helper_functions----------------//
void			check_if_empty(char *s, t_node **stack_a);
int				is_instack(t_node *stack_t_a, int content);
int				_atoi(char *s, t_node *stack_a);
int				is_sorted(t_node *stack_a);
void			_error(t_node **stack_a);
void			__free(char **str, int j);
// --------------intsruction_rules_functions----------------//
void			___push(t_node **stack_a, t_node **stack_b);
void			_sa(t_node *stack_a);
void			_sb(t_node *stack_b);
void			_ss(t_node *stack_a, t_node *stack_b);
void			_pa(t_node **stack_a, t_node **stack_b);
void			_pb(t_node **stack_a, t_node **stack_b);
void			_ra(t_node **stack_a);
void			_rb(t_node **stack_b);
void			_rr(t_node **stack_a, t_node **stack_b);
void			_rra(t_node **stack_a);
void			_rrb(t_node **stack_b);
void			_rrr(t_node **stack_a, t_node **stack_b);
// -----------------linked_list_functions-------------------//
t_node			*new_d_list(int content);
void			create_list(t_node **stack_a, int content);
t_node			*last_node(t_node *stack_a);
int				__lstsize(t_node *lst);

#endif
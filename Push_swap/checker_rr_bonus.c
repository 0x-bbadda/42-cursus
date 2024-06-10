/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_rr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:42:59 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/02 16:08:14 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	_rra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *stack_a;
	if (!tmp)
		return ;
	tail = last_node(*stack_a);
	*stack_a = tail;
	tail->next = tmp;
	while (tmp->next != tail)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	_rrb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *stack_b;
	if (!tmp)
		return ;
	tail = last_node(*stack_b);
	*stack_b = tail;
	tail->next = tmp;
	while (tmp->next != tail)
		tmp = tmp->next;
	tmp->next = NULL;
}

void	_rrr(t_node **stack_a, t_node **stack_b)
{
	_rra(stack_a);
	_rrb(stack_b);
}

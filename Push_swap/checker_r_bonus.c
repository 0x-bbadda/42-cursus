/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_r_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:42:01 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 01:17:28 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	_ra(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *stack_a;
	tail = last_node(*stack_a);
	*stack_a = tmp->next;
	tail->next = tmp;
	tmp->next = NULL;
}

void	_rb(t_node **stack_b)
{
	t_node	*tmp;
	t_node	*tail;

	tmp = *stack_b;
	if (!tmp)
		return ;
	tail = last_node(*stack_b);
	*stack_b = tmp->next;
	tail->next = tmp;
	tmp->next = NULL;
}

void	_rr(t_node **stack_a, t_node **stack_b)
{
	_ra(stack_a);
	_rb(stack_b);
}

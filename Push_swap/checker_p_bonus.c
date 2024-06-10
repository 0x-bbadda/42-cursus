/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_p_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:39:44 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 01:52:51 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	___push(t_node **stack_from, t_node **stack_to)
{
	t_node	*tmp;

	tmp = *stack_from;
	if (tmp == NULL || stack_from == NULL)
		return ;
	*stack_from = (*stack_from)->next;
	tmp->next = (*stack_to);
	(*stack_to) = tmp;
}

void	_pa(t_node **stack_a, t_node **stack_b)
{
	if (!stack_b)
		return ;
	___push(stack_b, stack_a);
}

void	_pb(t_node **stack_a, t_node **stack_b)
{
	if (!stack_a)
		return ;
	___push(stack_a, stack_b);
}

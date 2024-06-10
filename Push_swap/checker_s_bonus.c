/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_s_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:40:50 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 00:20:55 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	_sa(t_node *stack_a)
{
	t_node	*tmp;
	int		tmp2;

	tmp = stack_a->next;
	if (!tmp || !stack_a)
		return ;
	tmp2 = tmp->content;
	tmp->content = stack_a->content;
	stack_a->content = tmp2;
}

void	_sb(t_node *stack_b)
{
	t_node	*tmp;
	int		tmp2;

	if (!stack_b)
		return ;
	tmp = stack_b->next;
	tmp2 = tmp->content;
	tmp->content = stack_b->content;
	stack_b->content = tmp2;
}

void	_ss(t_node *stack_a, t_node *stack_b)
{
	_sa(stack_a);
	_sb(stack_b);
}

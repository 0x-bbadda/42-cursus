/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:48:42 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/02 16:10:25 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack_a;
	tail = __last_node(*stack_a);
	*stack_a = tail;
	tail->next = tmp;
	while (tmp->next != tail)
		tmp = tmp->next;
	tmp->next = NULL;
	write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack_b;
	tail = __last_node(*stack_b);
	*stack_b = tail;
	tail->next = tmp;
	while (tmp->next != tail)
		tmp = tmp->next;
	tmp->next = NULL;
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

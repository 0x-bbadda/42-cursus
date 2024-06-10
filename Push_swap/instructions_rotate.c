/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:48:48 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/02 15:37:48 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack_a;
	tail = __last_node(*stack_a);
	*stack_a = tmp->next;
	tail->next = tmp;
	tmp->next = NULL;
	write (1, "ra\n", 3);
}

t_list	*rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tail;

	tmp = *stack_b;
	tail = __last_node(*stack_b);
	*stack_b = tmp->next;
	tail->next = tmp;
	tmp->next = NULL;
	write (1, "rb\n", 3);
	return (*stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write (1, "rr\n", 3);
}

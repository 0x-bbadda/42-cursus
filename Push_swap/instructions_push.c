/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:50:04 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/02 15:39:09 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__push(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*head_b;
	t_list	*head_a;

	head_b = *stack_b;
	head_a = *stack_a;
	tmp = head_a;
	head_a = head_a->next;
	*stack_a = head_a;
	if (!head_b)
	{
		head_b = tmp;
		head_b->next = NULL;
		*stack_b = head_b;
	}
	else
	{
		tmp->next = head_b;
		*stack_b = tmp;
	}
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	__push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

t_list	*pb(t_list **stack_a, t_list **stack_b)
{
	__push(stack_a, stack_b);
	write(1, "pb\n", 3);
	return (*stack_a);
}

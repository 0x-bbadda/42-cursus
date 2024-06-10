/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:50:55 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 00:33:19 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__2_num_case(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a->next;
	if (stack_a->content > tmp->content)
		sa(stack_a, tmp);
}

void	__3_num_case(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp;
	int		d1;
	int		d2;

	tmp1 = *stack_a;
	tmp = tmp1->next;
	d1 = tmp1->content;
	d2 = tmp->content;
	if (__is_sorted(*stack_a) == 0 && d1 < d2)
	{
		rra(stack_a);
		__3_num_case(stack_a);
	}
	else if (__is_sorted(*stack_a) == 0)
	{
		sa(*stack_a, tmp);
		__3_num_case(stack_a);
	}
}

void	__4_num_case(t_list **stack_a, t_list **stack_b)
{
	get_min_top(stack_a, get_min_num(stack_a));
	pb(stack_a, stack_b);
	if (__is_sorted(*stack_a) == 0)
		__3_num_case(stack_a);
	pa(stack_b, stack_a);
}

void	__5_num_case(t_list **stack_a, t_list **stack_b)
{
	get_min_top(stack_a, get_min_num(stack_a));
	pb(stack_a, stack_b);
	if (__is_sorted(*stack_a) == 0)
		__4_num_case(stack_a, stack_b);
	pa(stack_b, stack_a);
}

void	__simple_sort(t_list **stack_a, t_list **stack_b, int lenth)
{
	if (__is_sorted(*stack_a) || lenth == 0 || lenth == 1)
		return ;
	if (lenth == 2)
		__2_num_case(*stack_a);
	else if (lenth == 3)
		__3_num_case(stack_a);
	else if (lenth == 4)
		__4_num_case(stack_a, stack_b);
	else if (lenth == 5)
		__5_num_case(stack_a, stack_b);
}

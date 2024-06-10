/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:41:34 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 00:21:09 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_node_pos(t_list *stack_a, int m)
{
	int	i;

	if (!stack_a)
		return (0);
	i = 1;
	while (stack_a->next)
	{
		if (stack_a->content == m)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (i);
}

int	get_min_num(t_list **stack_a)
{
	t_list	*tmp;
	int		min;

	tmp = *stack_a;
	min = tmp->content;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	get_min_top(t_list **stack_a, int min)
{
	t_list	*tmp;
	int		i;
	int		middle;

	if (*stack_a == NULL)
		return ;
	middle = __lstsize(*stack_a) / 2;
	i = get_node_pos(*stack_a, min);
	tmp = *stack_a;
	if (tmp)
	{
		while (tmp->content != min)
		{
			if (i <= middle)
				ra(stack_a);
			else if (i > middle)
				rra(stack_a);
			tmp = *stack_a;
		}
	}
}

void	get_max_top(t_list **stack_b, int max)
{
	t_list	*tmp;
	int		i;
	int		avrg;

	if (*stack_b == NULL)
		return ;
	avrg = __lstsize(*stack_b) / 2;
	i = get_node_pos(*stack_b, max);
	tmp = *stack_b;
	if (tmp)
	{
		while (tmp->content != max)
		{
			i++;
			if (i < avrg)
				*stack_b = rb(stack_b);
			else if (i >= avrg)
				rrb(stack_b);
			tmp = *stack_b;
		}
	}
}

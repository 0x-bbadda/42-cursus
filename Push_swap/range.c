/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:32:05 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/02 17:39:11 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	__push_to_b(t_list **stack_a, t_list **stack_b, int start, int end)
{
	t_list	*tmp;

	tmp = *stack_a;
	if (tmp)
	{
		if (tmp->content >= start && tmp->content <= end)
		{
			*stack_a = pb(&tmp, stack_b);
			__push_to_b(stack_a, stack_b, ++start, ++end);
		}
		else if (tmp->content < start)
		{
			*stack_a = pb(&tmp, stack_b);
			rb(stack_b);
			__push_to_b(stack_a, stack_b, ++start, ++end);
		}
		else if (tmp->content > end)
		{
			ra(stack_a);
			__push_to_b(stack_a, stack_b, start, end);
		}
	}
}

void	__push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		max;

	tmp = *stack_b;
	max = __lstsize(tmp) - 1;
	if (tmp)
	{
		if (tmp->content == max)
		{
			pa(stack_a, &tmp);
			if (!tmp)
				return ;
			__push_to_a(stack_a, &tmp);
		}
		else
		{
			get_max_top(&tmp, max);
			__push_to_a(stack_a, &tmp);
		}
	}
}

t_list	*get_sorted_stack(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*index;
	int		temp;

	index = NULL;
	if (stack_a)
	{
		tmp = stack_a;
		while (tmp->next)
		{
			index = tmp->next;
			while (index)
			{
				if (tmp->content > index->content)
				{
					temp = tmp->content;
					tmp->content = index->content;
					index->content = temp;
				}
				index = index->next;
			}
			tmp = tmp->next;
		}
	}
	return (stack_a);
}

t_list	*get_indexed_stack(t_list *stack_a, t_list *new_list)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		i;

	tmp1 = stack_a;
	while (tmp1)
	{
		i = 0;
		tmp = new_list;
		while (tmp)
		{
			if (tmp1->content == tmp->content)
			{
				tmp1->content = i;
				break ;
			}
			i++;
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
	}
	return (stack_a);
}

void	__range(t_list **stack_a, t_list **stack_b)
{
	t_list	*new_list;

	new_list = NULL;
	new_list = __duplicat_node(*stack_a);
	new_list = get_sorted_stack(new_list);
	*stack_a = get_indexed_stack(*stack_a, new_list);
	free_stack(&new_list);
	if (__lstsize(*stack_a) > 100)
		__push_to_b(stack_a, stack_b, 0, 33);
	if (__lstsize(*stack_a) <= 100)
		__push_to_b(stack_a, stack_b, 0, 15);
	__push_to_a(stack_a, stack_b);
}

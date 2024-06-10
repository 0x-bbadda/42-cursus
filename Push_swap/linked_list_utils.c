/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:22:15 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/02 17:54:44 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*__new_d_list(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new)
	{
		new->content = content;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

void	__create_list(t_list **stack_a, int content)
{
	t_list	*temp;
	t_list	*new;

	temp = *stack_a;
	if (is_instack(temp, content) == 0)
		new = __new_d_list(content);
	else
		ft_error(&temp);
	if (stack_a && new)
	{
		if (*stack_a == NULL)
			*stack_a = new;
		else
		{
			temp = *stack_a;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
			new->prev = temp;
		}
	}
}

t_list	*__last_node(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*last;

	tmp = stack_a;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

int	__lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*__duplicat_node(t_list *stack_a)
{
	t_list	*new_node;
	t_list	*new_list;
	t_list	*tail;
	t_list	*tmp;

	new_list = NULL;
	tmp = stack_a;
	if (stack_a == NULL)
		return (NULL);
	while (tmp)
	{
		new_node = __new_d_list(tmp->content);
		if (new_list == NULL)
		{
			new_list = new_node;
			tail = new_node;
		}
		else
		{
			tail->next = new_node;
			tail = tail->next;
		}
		tmp = tmp->next;
	}
	return (new_list);
}

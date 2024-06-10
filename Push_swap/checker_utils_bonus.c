/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:21:38 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 01:42:16 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_node	*new_d_list(int content)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new)
	{
		new->content = content;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

void	create_list(t_node **stack_a, int content)
{
	t_node	*temp;
	t_node	*new;

	temp = *stack_a;
	if (is_instack(temp, content) == 0)
		new = new_d_list(content);
	else
		_error(stack_a);
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

t_node	*last_node(t_node *stack_a)
{
	t_node	*tmp;
	t_node	*last;

	tmp = stack_a;
	while (tmp)
	{
		last = tmp;
		tmp = tmp->next;
	}
	return (last);
}

void	__free(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

int	__lstsize(t_node *lst)
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

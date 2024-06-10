/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_resource_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:47:55 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 01:42:36 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	_atoi(char *s, t_node *stack_a)
{
	long long int	r;
	int				i;
	int				signe;

	r = 0;
	i = 0;
	signe = 1;
	while (s[i] == ' ')
		i++;
	if (s[i] == '-')
		signe *= -1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 1)
			r = (r * 10) + (s[i] - 48);
		else
			_error(&stack_a);
		i++;
	}
	if ((r * signe) > 2147483647 || (r * signe) < -2147483648)
		_error(&stack_a);
	return (r * signe);
}

void	check_if_empty(char *s, t_node **stack_a)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		_error(stack_a);
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] == '\0')
			_error(stack_a);
		else if (s[i] != ' ')
			return ;
		i++;
	}
}

int	is_sorted(t_node *stack_a)
{
	t_node	*tmp;
	int		next;
	int		min;

	tmp = stack_a;
	tmp = tmp->next;
	while (tmp)
	{
		min = stack_a->content;
		next = tmp->content;
		if (next < min)
			return (0);
		stack_a = stack_a->next;
		tmp = tmp->next;
	}
	return (1);
}

int	is_instack(t_node *stack_a, int content)
{
	t_node	*temp;

	temp = stack_a;
	while (temp != NULL) 
	{
		if (temp->content == content) 
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	_error(t_node **stack_a)
{
	write(2, "Error\n", 6);
	stack_a = NULL;
	exit(0);
}

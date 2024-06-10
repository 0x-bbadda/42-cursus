/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:04:48 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/04 23:29:14 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__atoi(char *s, t_list *stack_a)
{
	int				i;
	long long int	r;
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
			ft_error(&stack_a);
		i++;
	}
	if ((r * signe) > 2147483647 || (r * signe) < -2147483648)
		ft_error(&stack_a);
	return (r * signe);
}

int	is_instack(t_list *stack_a, int content)
{
	t_list	*temp;

	temp = stack_a;
	while (temp != NULL) 
	{
		if (temp->content == content) 
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_error(t_list **stack_a)
{
	write(2, "Error\n", 6);
	free_stack(stack_a);
	exit(0);
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

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	if (!*stack)
		return ;
	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	*stack = NULL;
}

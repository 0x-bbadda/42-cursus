/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:04:38 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 00:16:04 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	__is_sorted(t_list *stack_a)
{
	t_list	*tmp;
	int		min;
	int		next;

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

void	__check_if_empty(char *s, t_list **stack_a)
{
	int	i;

	if (s[0] == '\0')
		ft_error(stack_a);
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' && s[i + 1] == '\0')
			ft_error(stack_a);
		else if (s[i] != ' ')
			return ;
		i++;
	}
}

static void	fill_stack(t_list **stack_a, char **av)
{
	t_index	index;
	char	**str;

	index.i = 0;
	while (av[++index.i])
	{
		__check_if_empty(av[index.i], stack_a);
		str = ft_split(av[index.i], ' ');
		index.j = -1;
		while (str[++index.j])
		{
			if (is_valid(str[index.j]) == 1)
				ft_error(stack_a);
			if (is_instack(*stack_a, __atoi(str[index.j], *stack_a)) == 1)
				ft_error(stack_a);
			__create_list(stack_a, __atoi(str[index.j], *stack_a));
		}
		__free(str, index.j);
	}
}

int	main(int ac, char **av)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	if (ac >= 2)
	{
		fill_stack(stack_a, av);
		if (__is_sorted(*stack_a) == 0)
		{
			if (__lstsize(*stack_a) <= 5)
				__simple_sort(stack_a, stack_b, __lstsize(*stack_a));
			else
				__range(stack_a, stack_b);
		}
		free_stack(stack_a);
	}
	return (0);
}

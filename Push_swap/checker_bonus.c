/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 02:21:41 by bbadda            #+#    #+#             */
/*   Updated: 2024/04/05 01:52:36 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	__check_instructions(t_node **stack_a, t_node **stack_b, char *s)
{
	if (ft_strncmp(s, "sa\n", 3) == 0)
		_sa(*stack_a);
	else if (ft_strncmp(s, "sb\n", 3) == 0)
		_sb(*stack_b);
	else if (ft_strncmp(s, "ss\n", 3) == 0)
		_ss(*stack_a, *stack_b);
	else if (ft_strncmp(s, "ra\n", 3) == 0)
		_ra(stack_a);
	else if (ft_strncmp(s, "rb\n", 3) == 0)
		_rb(stack_b);
	else if (ft_strncmp(s, "rr\n", 3) == 0)
		_rr(stack_a, stack_b);
	else if (ft_strncmp(s, "rra\n", 4) == 0)
		_rra(stack_a);
	else if (ft_strncmp(s, "rrb\n", 4) == 0)
		_rrb(stack_b);
	else if (ft_strncmp(s, "rrr\n", 4) == 0)
		_rrr(stack_a, stack_b);
	else if (ft_strncmp(s, "pa\n", 3) == 0)
		_pa(stack_a, stack_b);
	else if (ft_strncmp(s, "pb\n", 3) == 0)
		_pb(stack_a, stack_b);
	else
		_error(stack_a);
}

static void	my_checker(t_node **stack_a, t_node **stack_b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		__check_instructions(stack_a, stack_b, s);
		free(s);
		s = get_next_line(0);
	}
	if (__lstsize(*stack_b) < 1 && is_sorted(*stack_a) == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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

static void	fill_stack(t_node **stack_a, char **av)
{
	t_index	index;
	char	**str;

	str = NULL;
	index.i = 0;
	while (av[++index.i])
	{
		check_if_empty(av[index.i], stack_a);
		str = ft_split(av[index.i], ' ');
		index.j = -1;
		while (str[++index.j])
		{
			if (is_valid(str[index.j]) == 1)
				_error(stack_a);
			if (is_instack(*stack_a, _atoi(str[index.j], *stack_a)) == 1)
				_error(stack_a);
			create_list(stack_a, _atoi(str[index.j], *stack_a));
		}
		__free(str, index.j);
	}
}

int	main(int ac, char **av)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = (t_node **)malloc(sizeof(t_node));
	stack_b = (t_node **)malloc(sizeof(t_node));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	if (ac >= 2)
	{
		fill_stack(stack_a, av);
		my_checker(stack_a, stack_b);
	}
	return (0);
}

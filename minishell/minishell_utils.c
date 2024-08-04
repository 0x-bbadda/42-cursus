/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:15:23 by bbadda            #+#    #+#             */
/*   Updated: 2024/07/08 11:14:25 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int	cmp(const char *s1, const char *s2)
{
	int i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return 0;
		i++;
	}
	return (1);
}

void	__error(int i)
{
	if (i == 0)
		printf("%s\n", ARGS_ERROR);
	if (i == 1)
	{
		printf("syntax error❌\n");
	}
}

void	init_members(t_minis *is)
{
	is->Argument = NULL;
	is->Command = NULL;
	is->Operator = NULL;
}

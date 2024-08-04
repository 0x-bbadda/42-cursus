/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 11:04:33 by bbadda            #+#    #+#             */
/*   Updated: 2024/07/08 12:23:41 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*creat_list(t_minis *is)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if(!node)
		return (NULL);
	if (node)
	{
		node->content = is;
		node->next = NULL;
	}
	return (node);
}

void	add_list_back(t_list **lst, t_minis *is)
{
	t_list	*tmp;
	t_list	*new;

	print_full_command(lst);
	new = creat_list(is);
	if (new && lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

char	*get_pipe(char *line)
{
	int i = 0;
	char	**str;
	str = ft_split(line, ' ');
	while (str[i])
	{
		if (cmp(str[i], "|") && !str[i + 1])
			return (str[i]);
		i++;
	}
	return (NULL);
}

void	tokenize(t_minis *is, char *str)
{
	if (cmp(str, "ls") || cmp(str, "cd") || cmp(str, "pwd") 
		|| cmp(str, "echo") || cmp(str, "awk") || cmp(str, "wc"))
			is->Command = str;
	else if (cmp(str, "|") || cmp(str, ">") | cmp(str, "<") 
					|| cmp(str, ">>") || cmp(str, "<<"))
			is->Operator = str;
	else if (str)
		is->Argument = str;
	else
		printf("(null)\n");
}
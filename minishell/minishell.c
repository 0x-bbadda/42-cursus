/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:14:08 by bbadda            #+#    #+#             */
/*   Updated: 2024/07/08 12:23:33 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_full_command(t_list **lst)
{
	static int i;
	
	i += 1;
	printf("i = %d\n", i);
	if (lst == NULL)
		printf("no\n");
    t_list *node = *lst;

    while (node != NULL)
    {
        if (node->content != NULL)
		{
            if (node->content->Command != NULL)
                printf("Command %d: %s\n", i, node->content->Command);
			else 
                printf("Command : (null)\n");

            if (node->content->Argument != NULL)
                printf("Argument %d: %s\n", i, node->content->Argument);
			else
                printf("Argument : (null)\n");
            if (node->content->Operator != NULL)
                printf("Operator %d: %s\n", i, node->content->Operator);
			else
                printf("Operator : (null)\n");
        }
		else 
            printf("Content is NULL.\n");
        node = node->next;
    }
}


int main (void)
{
	t_minis		*is;
	t_list		**lst;
	int 		i;
	int 		j;
	char 		**str;
	char 		**s;
	init_members(is);
	lst = (t_list **)malloc(sizeof(t_list));
	*lst = NULL;
	while (1)
	{
		char *line = readline("⑉➤minishell-$");
		if (get_pipe(line))
			__error(1);
		str = ft_split(line, '|');
		i = -1;
		while(str[++i])
		{
			s = ft_split(str[i], ' ');
			j = -1;
			while (s[++j])
				tokenize(is, s[j]);
			add_list_back(lst, is);
			free(s);
		}
		// print_full_command(lst);
		init_members(is);
		free(str);
	}
}
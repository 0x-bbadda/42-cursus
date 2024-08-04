/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:14:11 by bbadda            #+#    #+#             */
/*   Updated: 2024/07/08 12:24:06 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_minis
{
	char	*Command;
	char	*Argument;
	char	*Operator;
	int		n;
}t_minis;

typedef struct s_split
{
	char	**list;
	char	c;
}t_split;

typedef struct s_list
{
	struct s_list	*next;
	t_minis			*content;
}t_list;

# define ARGS_ERROR  "number of arguments"

char		**ft_split(char const *s, char c);
int			cmp(const char *s1, const char *s2);
void		tokenize(t_minis *is, char *str);
char		*get_pipe(char *line);
int			ft_strlen(const char *str);
void		init_members(t_minis *is);
t_list		*creat_list(t_minis *is);
void		add_list_back(t_list **lst, t_minis *is);
void		print_full_command(t_list **lst);
void	    __error(int i);

#endif
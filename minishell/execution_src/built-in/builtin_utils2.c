/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:05:51 by asalmi            #+#    #+#             */
/*   Updated: 2024/11/16 21:02:49 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(const char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (1);
	if (!ft_strcmp(cmd, "cd"))
		return (1);
	if (!ft_strcmp(cmd, "pwd"))
		return (1);
	if (!ft_strcmp(cmd, "env"))
		return (1);
	if (!ft_strcmp(cmd, "export"))
		return (1);
	if (!ft_strcmp(cmd, "unset"))
		return (1);
	if (!ft_strcmp(cmd, "exit"))
		return (1);
	return (0);
}

void	execute_builtin(t_token *cmd, t_env **env)
{
	int	res;

	if (!ft_strcmp(cmd->command, "echo"))
		res = ft_echo(cmd);
	if (!ft_strcmp(cmd->command, "cd"))
		res = ft_cd(cmd, *env);
	if (!ft_strcmp(cmd->command, "pwd"))
		res = ft_pwd();
	if (!ft_strcmp(cmd->command, "env"))
		res = ft_env(cmd, *env);
	if (!ft_strcmp(cmd->command, "export"))
		res = ft_export(cmd, env);
	if (!ft_strcmp(cmd->command, "unset"))
		res = ft_unset(cmd, env);
	if (!ft_strcmp(cmd->command, "exit"))
		res = ft_exit(cmd, *env);
	if (res == 0)
		(*env)->exit_status = 0;
	else if (res == 1)
		(*env)->exit_status = 1;
}

int	add_oldpath_env(t_env *head, char *old_pwd)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (!new)
		return (1);
	new->content = malloc(sizeof(t_content));
	if (!new->content)
	{
		free(new);
		return (1);
	}
	new->content->var = ft_strdup("OLDPWD");
	new->content->value = ft_strdup(old_pwd);
	new->next = NULL;
	add_to_env(&head, new);
	return (0);
}

void	check_pwd_env(t_env *env, char *pwd, char *old_pwd, int *flg)
{
	while (env)
	{
		if (!ft_strcmp(env->content->var, "PWD"))
		{
			free(env->content->value);
			env->content->value = ft_strdup(pwd);
		}
		if (!ft_strcmp(env->content->var, "OLDPWD"))
		{
			free(env->content->value);
			env->content->value = ft_strdup(old_pwd);
			*flg = 1;
		}
		env = env->next;
	}
}

int	update_pwd(t_env *env, char *old_pwd)
{
	char	pwd[PATH_MAX];
	t_env	*head;
	int		flg;

	flg = 0;
	head = env;
	if (getcwd(pwd, sizeof(pwd)) == NULL)
	{
		perror("getcwd");
		return (1);
	}
	check_pwd_env(env, pwd, old_pwd, &flg);
	if (flg == 0)
	{
		if (add_oldpath_env(head, old_pwd) != 0)
			return (1);
	}
	return (0);
}

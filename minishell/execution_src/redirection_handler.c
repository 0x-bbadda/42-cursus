/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalmi <asalmi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 19:16:59 by asalmi            #+#    #+#             */
/*   Updated: 2024/11/16 21:20:58 by asalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	open_file_output(t_opr *file, int flags, t_env *env)
{
	int	fd;

	fd = -1;
	fd = open(file->file_name, flags, 0644);
	if (fd < 0)
	{
		perror("open");
		env->exit_status = 1;
	}
	return (fd);
}

int	handle_output_readirection(t_opr *file, t_env *env)
{
	int	fd;

	fd = open_file_output(file, O_WRONLY | O_CREAT | O_TRUNC, env);
	if (fd < 0)
		return (-1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	handle_append_readirection(t_opr *file, t_env *env)
{
	int	fd;

	fd = open_file_output(file, O_WRONLY | O_CREAT | O_APPEND, env);
	if (fd < 0)
		return (-1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	handle_input_readirection(t_opr *file, t_env *env)
{
	int	fd;

	fd = open(file->file_name, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		env->exit_status = 1;
		return (-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

int	redirection_handler(t_token *cmd, t_env *env)
{
	while (cmd->file)
	{
		if (!ft_strcmp(cmd->file->opr, ">")
			&& handle_output_readirection(cmd->file, env) == -1)
			return (-1);
		if (!ft_strcmp(cmd->file->opr, "<")
			&& handle_input_readirection(cmd->file, env) == -1)
			return (-1);
		if (!ft_strcmp(cmd->file->opr, ">>")
			&& handle_append_readirection(cmd->file, env) == -1)
			return (-1);
		cmd->file = cmd->file->next;
	}
	env->exit_status = 0;
	return (0);
}

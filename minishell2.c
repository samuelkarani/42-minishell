/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 22:08:32 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 22:22:38 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_file_exec(char *path)
{
	if (check_valid_path(path))
	{
		if (check_exec_path(path))
			return (1);
		else
		{
			permission_denied(path);
			return (0);
		}
	}
	else
	{
		ft_printf("minishell: no such file or directory: %s\n", path);
		return (0);
	}
}

void	*no_exec(char *path, char *cmd)
{
	free(path);
	permission_denied(cmd);
	return (NULL);
}

char	*find_cmd_path(t_node *env_lst, char *cmd)
{
	char	**paths;
	char	*path;
	int		i;

	path = NULL;
	paths = get_paths(env_lst);
	i = 0;
	while (paths[i])
	{
		path = join_btwn(paths[i], cmd, "/");
		if (check_valid_path(path))
		{
			free_all(paths);
			if (check_exec_path(path))
				return (path);
			else
				return (no_exec(path, cmd));
		}
		free(path);
		i++;
	}
	free_all(paths);
	ft_printf("%s: Command not found\n", cmd);
	return (NULL);
}

void	exec(t_node *env_lst, char **args)
{
	char	*path;
	char	**sh_environ;

	sh_environ = NULL;
	if (**args != '/' && !ft_startswith(*args, "./"))
		path = find_cmd_path(env_lst, *args);
	else if (check_file_exec(*args))
		path = ft_strdup(*args);
	else
		path = NULL;
	if (path)
	{
		if (fork() == 0)
		{
			sh_environ = convert(env_lst);
			signal(SIGINT, SIG_DFL);
			execve(path, args, sh_environ);
		}
		else
			wait(NULL);
	}
	free(path);
	if (sh_environ)
		free_all(sh_environ);
}

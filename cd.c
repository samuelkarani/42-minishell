/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:22:27 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 21:40:30 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_print(char *s)
{
	while (*s)
	{
		if (!ft_isprint(*s))
			return (1);
		s++;
	}
	return (0);
}

void	change_pwd(t_node **env, char *old_path)
{
	char	*abs_path;

	abs_path = getcwd(NULL, 0);
	add(env, "OLDPWD", old_path);
	add(env, "PWD", abs_path);
	free(abs_path);
}

char	*get_path(t_node **env, char **args)
{
	t_node	*f;
	char	*path;

	path = NULL;
	if (!*args)
	{
		path = ft_strdup("~");
		replace_arg(*env, &path);
	}
	else if (ft_strlen_arr(args) > 1)
		ft_putendl("cd: Too many arguments.");
	else if (check_print(*args))
		ft_putendl("cd: Invalid characters.");
	else if (ft_strequ(*args, "-"))
	{
		if ((f = find(*env, "OLDPWD")))
			path = ft_strdup(f->val);
		else
			ft_putendl("OLDPWD not set");
	}
	else
		path = ft_strdup(*args);
	return (path);
}

void	cd(t_node **env, char **args)
{
	char	*path;
	char	*old_path;

	if (!(path = get_path(env, args)))
		return ;
	if (is_dir(path))
	{
		if (check_valid_path(path))
		{
			if (check_exec_path(path))
			{
				old_path = getcwd(NULL, 0);
				chdir(path);
				change_pwd(env, old_path);
				free(old_path);
			}
			else
				permission_denied(path);
		}
		else
			ft_printf("cd: no such file or directory: %s\n", path);
	}
	else
		ft_printf("cd: not a directory: %s\n", path);
	free(path);
}

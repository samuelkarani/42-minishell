/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:45:38 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 21:24:36 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int		get_files(char *dpath, char **paths, int idx)
{
	DIR				*dir;
	struct dirent	*dir_entry;
	char			*s;

	if ((dir = opendir(dpath)))
	{
		while ((dir_entry = readdir(dir)))
		{
			s = join_btwn(dpath, dir_entry->d_name, "/");
			if (check_rfile_l(s))
			{
				if (check_exec_path(s))
					paths[idx++] = s;
				else
					free(s);
			}
			else
			{
				free(s);
			}
		}
		closedir(dir);
	}
	return (idx);
}

void	clone_paths(char **dst, char **src)
{
	char	**p;
	char	*tmp;
	int		i;
	int		idx;

	p = src;
	idx = 0;
	i = 0;
	while (*src)
	{
		if (i == MAX_PATHS)
			break ;
		tmp = *src++;
		idx = get_files(tmp, dst, idx);
		free(tmp);
		i++;
	}
	dst[idx] = NULL;
	free(p);
	sort(dst);
}

char	**get_paths(t_node *env_lst)
{
	char	**paths;
	t_node	*path;

	if (!(path = find(env_lst, "PATH")))
		return (create_arg_null());
	if (ft_strchr(path->val, ':'))
		paths = ft_strsplit(path->val, ':');
	else
		paths = create_arg(path->val);
	return (paths);
}

char	*one_of_starts_with(char **options, char *s)
{
	char	*bname;

	while (*options)
	{
		bname = basename(*options);
		if (ft_startswith(bname, s))
			return (ft_strdup(bname));
		options++;
	}
	return (NULL);
}

int		autocomplete(char **line, char **paths)
{
	char	*ret;
	int		c;

	c = 0;
	if ((ret = one_of_starts_with((char *[]){"cd", "env", "echo", "setenv",
		"unsetenv", "exit", NULL}, *line)))
	{
		free(*line);
		*line = ret;
		c = 1;
	}
	else if (paths && (ret = one_of_starts_with(paths, *line)))
	{
		free(*line);
		*line = ret;
		c = 1;
	}
	return (c);
}

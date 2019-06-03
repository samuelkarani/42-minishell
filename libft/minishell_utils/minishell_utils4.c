/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:46:22 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 21:39:24 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int		check_valid_path(char *path)
{
	return (access(path, F_OK) != -1);
}

int		check_exec_path(char *path)
{
	return (access(path, X_OK) != -1);
}

int		check_rfile_l(char *fpath)
{
	struct stat s;

	lstat(fpath, &s);
	return (S_ISREG(s.st_mode));
}

int		is_dir(char *path)
{
	struct stat s;

	stat(path, &s);
	return (S_ISDIR(s.st_mode));
}

char	*basename(char *filename)
{
	char	*p;

	p = ft_strrchr(filename, '/');
	return (p ? p + 1 : filename);
}

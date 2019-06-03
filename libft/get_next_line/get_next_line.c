/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 22:41:32 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 20:42:46 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strjoin_free(char **line, char *buf)
{
	char	*tmp;

	tmp = *line;
	*line = ft_strjoin(*line, buf);
	free(tmp);
}

void	apply_autocomplete(char *line)
{
	ft_putstr("\033[A\033[2C");
	ft_putstr(line);
	ft_putstr("\n");
}

int		get_next_line(const int fd, char **line, t_node *env)
{
	int			n;
	char		buf[2];
	static char *paths[MAX_PATHS];

	if (!paths[0])
		clone_paths(paths, get_paths(env));
	while ((n = read(fd, buf, 1)) > 0)
	{
		buf[n] = 0;
		if (*buf == '\n')
			return (1);
		if (*buf == '\t' && *line && autocomplete(line, paths))
			apply_autocomplete(*line);
		ft_strjoin_free(line, buf);
	}
	free_paths(paths);
	return (*line ? 1 : n);
}

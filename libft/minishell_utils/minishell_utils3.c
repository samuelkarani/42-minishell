/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:47:15 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 21:39:30 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

char	*join_btwn(char *a, char *b, char *btwn)
{
	char	*r;
	char	*s;

	r = ft_strjoin(btwn, b);
	s = ft_strjoin(a, r);
	free(r);
	return (s);
}

char	**create_arg(char *s)
{
	char	**ret;

	ret = malloc(2 * sizeof(char *));
	ret[0] = ft_strdup(s);
	ret[1] = NULL;
	return (ret);
}

char	**create_arg_null(void)
{
	char	**ret;

	ret = malloc(1 * sizeof(char *));
	ret[0] = NULL;
	return (ret);
}

void	free_paths(char **paths)
{
	while (*paths)
	{
		free(*paths);
		*paths++ = NULL;
	}
}

void	sort(char **lst)
{
	char	*tmp;
	int		i;
	int		j;
	int		c;

	i = 0;
	while (lst[i + 1])
	{
		j = 0;
		c = 0;
		while (lst[j + 1])
		{
			if (ft_strcmp(lst[j], lst[j + 1]) > 0)
			{
				tmp = lst[j];
				lst[j] = lst[j + 1];
				lst[j + 1] = tmp;
				c = 1;
			}
			j++;
		}
		if (!c)
			break ;
		i++;
	}
}

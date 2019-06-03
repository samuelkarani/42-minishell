/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 20:47:12 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 20:55:27 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int		ft_startswith(char *s, char *c)
{
	while (*s && *c && *s == *c)
	{
		s++;
		c++;
	}
	return (!*c);
}

int		ft_strlen_arr(char **s)
{
	int count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

int		ft_strchr_all(char *s, int c)
{
	while (*s)
	{
		if (*s != c)
			return (0);
		s++;
	}
	return (1);
}

int		ft_count_char(char *s, char c)
{
	char	*r;
	int		count;

	count = 0;
	if ((r = ft_strchr(s, c)))
		count = 1 + ft_count_char(r + 1, c);
	return (count);
}

int		ft_strreplace(char **s, int c)
{
	char	*ret;
	char	*tmp;
	int		count;
	int		i;
	int		j;

	if ((j = ft_count_char(*s, c)))
	{
		count = ft_strlen(*s) - j;
		ret = malloc((count + 1) * sizeof(char));
		ret[count] = 0;
		i = 0;
		j = 0;
		while ((*s)[i])
			(*s)[i] != c ? ret[j++] = (*s)[i++] : i++;
		tmp = *s;
		*s = ret;
		free(tmp);
		return (1);
	}
	else
		return (0);
}

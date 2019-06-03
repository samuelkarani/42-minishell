/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:51:01 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 22:36:36 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	permission_denied(char *s)
{
	ft_printf("%s: permission denied\n", s);
}

int		ft_strdelcnt(const char *s, char *c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (ft_strchr(c, s[i]) && (i > 0 && !ft_strchr(c, s[i - 1])))
			count++;
		if (!s[i + 1] && !ft_strchr(c, s[i]))
			count++;
		i++;
	}
	return (count);
}

char	**ft_strsplit_m(char const *s, char *c)
{
	int		i;
	int		start;
	int		idx;
	int		count;
	char	**ret;

	if (!s || !c)
		return (NULL);
	count = ft_strdelcnt(s, c);
	ret = (char **)ft_memalloc(sizeof(char *) * count + 1);
	i = 0;
	idx = 0;
	while (s[i])
	{
		if (!ft_strchr(c, s[i]) && (i == 0 || (i > 0
			&& ft_strchr(c, s[i - 1]))))
			start = i;
		if (i > 0 && ft_strchr(c, s[i]) && !ft_strchr(c, s[i - 1]))
			ret[idx++] = ft_strsub(s, start, i - start);
		else if (i > 0 && !s[i + 1] && !ft_strchr(c, s[i]))
			ret[idx++] = ft_strsub(s, start, i - start + 1);
		i++;
	}
	ret[idx] = NULL;
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 00:35:47 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 22:36:07 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void	print_all(char **args)
{
	while (*args)
		ft_putendl(*args++);
}

void	free_all(char **args)
{
	char **s;

	s = args;
	while (*args)
		free(*args++);
	free(s);
}

int		one_of(char **options, char *s)
{
	while (*options)
	{
		if (ft_strequ(*options, s))
			return (1);
		options++;
	}
	return (0);
}

int		check_invalid(char *s)
{
	if (!ft_strlen(s))
		return (1);
	while (*s)
	{
		if (!ft_isalnum(*s))
			return (1);
		s++;
	}
	return (0);
}

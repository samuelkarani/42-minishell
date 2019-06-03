/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:16:05 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 22:08:04 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env_not_found(char *s)
{
	if (!*s)
		ft_putendl("No variable was given.");
	else
		ft_printf("%s: Undefined variable.\n", s);
	free(s);
	return (-1);
}

char	*join_path(char *prefix, char *name)
{
	int l;

	l = ft_strlen(prefix);
	if (prefix[--l] == '/')
		return (ft_strjoin(prefix, name));
	else
		return (join_btwn(prefix, name + 1, "/"));
}

int		replace_helper(t_node *env, char **args, char *s, char *r)
{
	t_node	*f;
	char	*tmp;

	if (s)
	{
		tmp = *args;
		if (!(f = find(env, s)))
			return (env_not_found(s));
		else
		{
			if (*tmp == '~')
				*args = join_path(f->val, tmp);
			else
				*args = ft_strdup(f->val);
		}
		free(tmp);
		free(s);
		if (r)
		{
			replace_arg(env, &r);
			*args = join_and_free(*args, r);
		}
	}
	return (0);
}

int		replace_arg(t_node *env, char **args)
{
	char	*s;
	char	*r;

	r = NULL;
	s = NULL;
	ft_strreplace(args, '"');
	if (**args == '~' && (!*(*args + 1) || *(*args + 1) == '/'))
		s = ft_strdup("HOME");
	if (**args == '$')
	{
		s = *args + 1;
		if (!ft_strchr_all(s, '$') && (r = ft_strchr(s + 1, '$')))
		{
			s = ft_strsub(s, 0, r - s);
			r = ft_strdup(r);
		}
		else
			s = ft_strdup(s);
	}
	return (replace_helper(env, args, s, r));
}

int		replace_args(t_node *env, char **args)
{
	while (*args)
	{
		if (replace_arg(env, args) == -1)
			return (-1);
		args++;
	}
	return (0);
}

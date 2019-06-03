/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:30:19 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/24 01:15:03 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_node *env_lst)
{
	char	**sh_environ;

	sh_environ = convert(env_lst);
	print_all(sh_environ);
	free_all(sh_environ);
}

void	init_env(t_node **env)
{
	extern char	**environ;
	char		**ret;

	while (*environ)
	{
		ret = ft_strsplit(*environ, '=');
		if (one_of((char*[]){"PWD", "PATH", "HOME", "TERM", "OLDPWD", NULL},
			ret[0]))
			add(env, ret[0], ret[1]);
		free_all(ret);
		environ++;
	}
}

void	set_env(t_node **env, char **args)
{
	if (!*args)
		print_env(*env);
	else if (ft_strlen_arr(args) > 2)
		ft_putendl("setenv: Too many arguments.");
	else if (check_invalid(*args))
		ft_putendl("setenv: Invalid argument(s).");
	else
		add(env, args[0], args[1]);
}

void	unset_env(t_node **env, char **args)
{
	if (!*args)
		ft_putendl("unsetenv: Too few arguments.");
	else
		delete(env, *args);
}

void	env(t_node **env_lst, char **args)
{
	t_node	*env_copy;
	char	**ret;

	if (!*args)
		print_env(*env_lst);
	else
	{
		env_copy = clone(*env_lst);
		while (*args && ft_strchr(*args, '='))
		{
			ret = ft_strsplit(*args, '=');
			set_env(&env_copy, ret);
			free_all(ret);
			args++;
		}
		if (!*args)
			print_env(env_copy);
		else
			parse_exec(args, &env_copy);
		destroy(&env_copy);
	}
}

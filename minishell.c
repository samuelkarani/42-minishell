/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:08:45 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/24 01:18:37 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_exec(char **args, t_node **env_lst)
{
	if (!*args || replace_args(*env_lst, args + 1) == -1)
		return ;
	if (ft_strequ(*args, "cd"))
		cd(env_lst, args + 1);
	else if (ft_strequ(*args, "echo"))
		echo(args + 1);
	else if (ft_strequ(*args, "env"))
		env(env_lst, args + 1);
	else if (ft_strequ(*args, "setenv"))
		set_env(env_lst, args + 1);
	else if (ft_strequ(*args, "unsetenv"))
		unset_env(env_lst, args + 1);
	else if (ft_strequ(*args, "exit"))
		exit_free(env_lst, args);
	else
		exec(*env_lst, args);
}

int		run(t_node *env, char *line)
{
	char	**args;
	int		ret;

	if (line && *line)
	{
		if (ft_strchr(line, ' ') || ft_strchr(line, '\t'))
			args = ft_strsplit_m(line, (char[]){' ', '\t'});
		else
			args = create_arg(line);
		parse_exec(args, &env);
		free_all(args);
		ret = 1;
	}
	else
		ret = 0;
	free(line);
	return (ret);
}

void	handle_cmds(t_node *env, char *line)
{
	char	**cmds;
	int		idx;

	cmds = ft_strsplit(line, ';');
	idx = 0;
	if (cmds)
	{
		while (cmds[idx])
			run(env, cmds[idx++]);
		free(cmds);
	}
	free(line);
}

int		init_vars(t_node **env, int ac, char **av)
{
	*env = NULL;
	init_env(env);
	signal(SIGINT, SIG_IGN);
	return (ac > 1 && ft_strequ(av[1], "-c"));
}

int		main(int ac, char **av)
{
	t_node	*env;
	char	*line;
	int		c;

	c = init_vars(&env, ac, av);
	while (1)
	{
		c ? ft_printf("%s$>%s", MAGENTA, GREEN) : ft_putstr("$>");
		line = NULL;
		if (get_next_line(STDIN_FILENO, &line, env) == 1)
		{
			ft_putstr(c ? YELLOW : "");
			if (line && ft_strchr(line, ';'))
				handle_cmds(env, line);
			else
			{
				if (!run(env, line))
					continue ;
			}
		}
	}
}

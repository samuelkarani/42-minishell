/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:35:36 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/24 01:14:01 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# include "libft/minishell_utils/minishell_utils.h"
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	exec(t_node *env_lst, char **args);
void	parse_exec(char **args, t_node **env_lst);

void	echo(char **args);
void	cd(t_node **env, char **args);
void	exit_free(t_node **env_lst, char **args);
int		replace_arg(t_node *env, char **args);
int		replace_args(t_node *env, char **args);
void	init_env(t_node **env);
void	set_env(t_node **env, char **args);
void	unset_env(t_node **env, char **key);
void	env(t_node **env, char **args);
void	permission_denied(char *s);

#endif

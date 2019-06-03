/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 15:35:53 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/19 17:07:37 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_free(t_node **env_lst, char **args)
{
	if (ft_strlen_arr(args) > 1)
		ft_putendl("exit: Expression Syntax.");
	else
	{
		free_all(args);
		destroy(env_lst);
		exit(0);
	}
}

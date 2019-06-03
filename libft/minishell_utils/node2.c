/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:00:46 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 21:02:11 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int		size(t_node *lst)
{
	int count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

char	**convert(t_node *lst)
{
	char	**ret;
	int		i;

	ret = malloc((size(lst) + 1) * sizeof(char *));
	i = 0;
	while (lst)
	{
		ret[i] = join_btwn(lst->key, lst->val, "=");
		lst = lst->next;
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

t_node	*clone(t_node *lst)
{
	t_node	*ret;

	ret = NULL;
	while (lst)
	{
		add(&ret, lst->key, lst->val);
		lst = lst->next;
	}
	return (ret);
}

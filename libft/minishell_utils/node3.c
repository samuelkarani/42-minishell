/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 21:00:05 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 21:00:59 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void	delone(t_node *one)
{
	free(one->key);
	free(one->val);
	free(one);
}

void	delete(t_node **lst, char *key)
{
	t_node	*prev;
	t_node	*list;

	list = *lst;
	prev = NULL;
	while (list)
	{
		if (ft_strcmp(list->key, key) == 0)
		{
			if (prev)
				prev->next = list->next;
			else
				*lst = list->next;
			delone(list);
		}
		else
			prev = list;
		list = list->next;
	}
}

void	destroy(t_node **lst)
{
	t_node	*next;

	while (*lst)
	{
		next = (*lst)->next;
		delone(*lst);
		*lst = next;
	}
	*lst = NULL;
}

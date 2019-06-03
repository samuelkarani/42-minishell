/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 23:31:00 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 21:01:33 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

char	*new(char *s)
{
	return (ft_strdup(s ? s : ""));
}

t_node	*create(char *key, char *val)
{
	t_node	*ret;

	ret = malloc(sizeof(t_node));
	ret->key = new(key);
	ret->val = new(val);
	ret->next = NULL;
	return (ret);
}

void	add(t_node **lst, char *key, char *val)
{
	t_node	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while (tmp)
		{
			if (ft_strcmp(tmp->key, key) == 0)
			{
				free(tmp->val);
				tmp->val = new(val);
				return ;
			}
			if (!tmp->next)
				break ;
			tmp = tmp->next;
		}
		tmp->next = create(key, val);
	}
	else
		*lst = create(key, val);
}

t_node	*find(t_node *lst, char *key)
{
	while (lst)
	{
		if (ft_strcmp(lst->key, key) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

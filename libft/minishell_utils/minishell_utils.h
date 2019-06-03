/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:09:11 by smbaabu           #+#    #+#             */
/*   Updated: 2019/05/23 22:36:15 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_UTILS_H
# define FT_MINISHELL_UTILS_H

# include "../libft.h"
# include <dirent.h>
# include <sys/stat.h>

# define MAX_PATHS 10000

typedef	struct	s_node
{
	char			*key;
	char			*val;
	struct s_node	*next;
}				t_node;

void			add(t_node **lst, char *key, char *val);
t_node			*find(t_node *lst, char *key);
char			**convert(t_node *lst);
void			delete(t_node **lst, char *key);
void			destroy(t_node **lst);
t_node			*clone(t_node *lst);

int				autocomplete(char **line, char **paths);
char			**create_arg(char *s);
char			**create_arg_null(void);
char			*join_btwn(char *a, char *b, char *btwn);
char			*basename (char *filename);
char			**get_paths(t_node *env_lst);
void			free_paths(char **paths);
void			clone_paths(char **dst, char **src);
void			sort(char **lst);
int				one_of(char **options, char *s);
void			free_all(char **args);
void			print_all(char **args);
int				check_invalid(char *s);

int				ft_strlen_arr(char **s);
char			**ft_strsplit_m(char const *s, char *c);
int				ft_strchr_all(char *s, int c);
int				ft_strreplace(char **s, int c);
int				ft_startswith(char *s, char *c);

int				check_valid_path(char *path);
int				check_exec_path(char *path);
int				check_rfile_l(char *fpath);
int				is_dir(char *path);

#endif

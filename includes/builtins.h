/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:21:10 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/26 00:04:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minishell.h>

# define NBR_BUILTINS 8

typedef int 		(*t_builtinfunc)(t_list**, t_cmd);

typedef struct				s_builtins
{
		char 				*name;
		t_builtinfunc 		func;
}							t_builtins;

char 				**get_builtins_name(void);
void 				**get_builtins_func(void);
t_list				*init_builtins(void);
int					do_builtin(t_list **environ, t_list *builtins, t_cmd cmd);
int 				is_builtins(t_list *builtins, char *command);

int 				printenv(t_list 	**env, t_cmd name);
int					exit_prog(t_list 	**env, t_cmd cmd);
int					ft_unsetenv(t_list **env, t_cmd cmd);
int					ft_clearenv(t_list **env, t_cmd cmd);
int					ft_setenv(t_list 	**env, t_cmd cmd);
int					echo(t_list 	**env, t_cmd cmd);
int					ft_cd(t_list 	**env, t_cmd cmd);

void display_builtin(t_list *builtins);

#endif
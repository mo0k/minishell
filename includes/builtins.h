/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:21:10 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:33:23 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <minishell.h>

# define NBR_BUILTINS 8
# define CWD 255

typedef int				(*t_builtinfunc)(t_list**, t_cmd);

typedef struct			s_builtins
{
	char			*name;
	t_builtinfunc	func;
}						t_builtins;

char					**get_builtins_name(void);
void					**get_builtins_func(void);
t_list					*init_builtins(void);
int						do_builtin(t_list **env, t_list *builtins, t_cmd cmd);
int						is_builtins(t_list *builtins, char *command);

int						ft_printenv(t_list **env, t_cmd name);
int						ft_exit_prog(t_list **env, t_cmd cmd);
int						ft_unsetenv(t_list **env, t_cmd cmd);
int						ft_clearenv(t_list **env, t_cmd cmd);
int						ft_setenv(t_list **env, t_cmd cmd);
int						ft_echo(t_list **env, t_cmd cmd);
int						ft_cd(t_list **env, t_cmd cmd);

#endif

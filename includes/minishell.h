/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:24:16 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:41:25 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_cmd
{
				char *path;
				char **opts;
				int ret;
}				t_cmd;

typedef struct 	s_env
{
				char *key;
				char *value;
}				t_env;

# include <unistd.h>
# include <stdio.h>
# include <libft.h>
# include <get_next_line.h>
//path binairy & tilde
char 			*format_tilde(char *cmd, t_list *env);
char 			**check_tilde(char **cmd, t_list *env);
# include <env.h>
# include <builtins.h>


t_cmd			get_path(char *env_path, char **cmd, t_list *env);

#endif
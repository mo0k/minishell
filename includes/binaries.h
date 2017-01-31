/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:59:22 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/31 15:01:57 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARIES_H
# define BINARIES_H

# include <minishell.h>
# include <sys/stat.h>

int			do_exec(t_list *environ, t_cmd cmd);
int			do_fork(char *binpath, char**av, char **env);
t_cmd		get_binpath(char *env_path, char **cmd, t_list *env);
char		**check_cmds(char **cmd, t_list *env);
void		check_cmd(char **cmd, t_list *env);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:59:22 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/05 01:02:47 by mo0ky            ###   ########.fr       */
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
char		*check_cmd(char *cmd, t_list *env);

#endif

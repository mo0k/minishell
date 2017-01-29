/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:59:22 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/29 22:16:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARIES_H
# define BINARIES_H

# include <minishell.h>
# include <sys/stat.h>

int			do_exec(t_list *environ, t_cmd cmd);
int			do_fork(char *binpath, char**av, char **env);
t_cmd		get_binpath(char *env_path, char **cmd, t_list *env);
char 		**check_cmd(char **cmd, t_list *env);
#endif
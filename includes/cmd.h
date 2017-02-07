/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 22:47:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/02/06 14:37:14 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <minishell.h>

t_cmd	exec_request(char *cmdline, t_cmd cmd, t_list **env, t_list *builtins);
void	init_cmd(t_cmd *cmd);

#endif

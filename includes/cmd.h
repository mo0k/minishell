/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 22:47:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/02/05 00:10:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include <minishell.h>

t_cmd	exec_request(char *cmdline, t_cmd cmd, t_list **environ, t_list *builtins);
void	init_cmd(t_cmd *cmd);

#endif
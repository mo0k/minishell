/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:59:22 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/26 00:42:56 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARIES_H
# define BINARIES_H

# include <minishell.h>

int			do_exec(t_list *environ, t_cmd cmd);
t_cmd		get_path(char *env_path, char **cmd, t_list *env);

#endif
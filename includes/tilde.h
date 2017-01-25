/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:55:38 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/25 23:57:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILDE_H
# define TILDE_H

# include <minishell.h>

char 		*format_tilde(char *cmd, t_list *env);
char 		**check_tilde(char **cmd, t_list *env);

#endif


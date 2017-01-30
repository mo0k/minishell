/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 23:55:38 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:27:25 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TILDE_H
# define TILDE_H

# include <minishell.h>

char		*format_tilde(char *cmd, t_list *env);
char		**check_tilde(char **cmd, t_list *env);

#endif

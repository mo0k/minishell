/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:39:17 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:27:45 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <minishell.h>

t_list			*env_to_lst(char **env);
char			**transfert_env(t_list *env);
char			*get_env(t_list *env, char *variable);
int				select_env(t_list *env, char *variable);
void			del_env(void *env, size_t size);
void			display(t_list *env);
void			display_all(t_list *env);

#endif

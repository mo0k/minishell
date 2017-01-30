/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:39:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 09:55:31 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <minishell.h>

t_list			*env_to_lst(char  **env);
char			**transfert_env(t_list *env);
char			*get_env(t_list *env, char *variable);
int				select_env(t_list *env, char *variable);
void			del_env(void *env, size_t size);
void			display(t_list *env);
void			display_all(t_list *env);

#endif
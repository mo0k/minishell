/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 10:36:36 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 17:33:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int	ft_clearenv(t_list **env, t_cmd cmd)
{
	(void)cmd;
	ft_lstdel(env, &del_env);
	return (0);
}

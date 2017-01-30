/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:38:24 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:47:42 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int			ft_printenv(t_list **env, t_cmd command)
{
	t_list	*cur;
	char	**cmd;

	if (!env || !*env || !command.opts)
		return (1);
	cmd = command.opts + 1;
	if (*cmd)
	{
		if ((cur = ft_lstselect(env, *cmd, &select_env)))
		{
			display(cur);
			return (0);
		}
	}
	else
	{
		ft_lstiter(*env, &display_all);
		return (0);
	}
	return (1);
}

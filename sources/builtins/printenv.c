/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:38:24 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 00:03:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int 		printenv(t_list 	**env, t_cmd command)
{
	//int		state;
	t_list	*cur;
	char	**cmd;

	if (!env || !command.opts)
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

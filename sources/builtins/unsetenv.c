/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:09:29 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 21:07:36 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int			ft_unsetenv(t_list **env, t_cmd command)
{
	t_list	*tmp;
	char	**cmd;
	int		ret;

	ret = 1;
	cmd = command.opts + 1;
	if (!*cmd || !*env)
		return (1);
	while (*cmd)
	{
		if ((tmp = ft_lstselect(env, *cmd, &select_env)))
		{
			if (tmp == *env)
				ft_lstdelfirst(env, &del_env);
			else
				ft_lstdelnext(&tmp->prev, &del_env);
			ret = 0;
		}
		else
			ret = 1;
		cmd++;
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:09:29 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:32:08 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int			ft_unsetenv(t_list **env, t_cmd command)
{
	t_list	*cur;
	char	**cmd;

	cmd = command.opts + 1;
	cur = *env;
	if (!*cmd || !*env)
		return (1);
	while (cur)
	{
		if (!ft_strcmp(*cmd, ((t_env*)(cur->content))->key))
		{
			if (cur == *env)
				ft_lstdelfirst(env, &del_env);
			else
				ft_lstdelnext(&cur->prev, &del_env);
			return (0);
		}
		cur = cur->next;
	}
	return (1);
}

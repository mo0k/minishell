/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:38:24 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:00:10 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>


void display_builtin(t_list *builtins)
{
	ft_putstr(((t_builtins *)(builtins->content))->name);
	write(1, "\n", 1);
}

int 		printenv(t_list 	**env, t_cmd command)
{
	int		state;
	t_list	*cur;
	char	**cmd;

	if (!env || !command.opts)
		return (1);
	cmd = command.opts + 1;
	state = 0;
	if (*cmd)
	{
		cur = *env;
		while (cur)
		{
			if (!ft_strcmp(*cmd, ((t_env*)(cur->content))->key))
			{
				display(cur);
				return (0);
			}
			cur = cur->next;
		}
		state = 1;
	}
	if (!state)
	{
		ft_lstiter(*env, &display_all);
		return (0);
	}
	return (1);
}

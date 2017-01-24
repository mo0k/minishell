/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:13:49 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:41:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char *format_tilde(char *cmd, t_list *env)
{
	char *home;
	char *tmp;

	if(*cmd == '~')
	{
		home = get_env(env, "HOME");
		printf("%d %d\n", *cmd, *(cmd+1));
		//return NULL;
		if (!*(cmd+1))
		{
			free(cmd);
			//if (!(cmd = ))
			cmd = (!home) ? ft_strdup("\0") : ft_strdup(home);
			return (cmd);
		}
		else if (*(cmd+1) == '/')
		{
			printf("par la\n");
			tmp = (!home) ? ft_strdup(cmd+1) : ft_strjoin(home, cmd + 1);
			free(cmd);
			return (tmp);
			printf("apres join\n");
		}
	}
	return (cmd);
}

char **check_tilde(char **cmd, t_list *env)
{
	int i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = format_tilde(cmd[i], env);
		i++;
	}
	return (cmd);
}

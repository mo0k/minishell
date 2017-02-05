/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:13:49 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/05 00:56:24 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char		*format_tilde(char *cmd, t_list *env)
{
	char	*home;
	char	*tmp;

	if (!cmd)
		return (NULL);
	if (*cmd == '~')
	{
		home = get_env(env, "HOME");
		if (!*(cmd + 1))
		{
			free(cmd);
			cmd = (!home) ? ft_strdup("\0") : ft_strdup(home);
			return (cmd);
		}
		else if (*(cmd + 1) == '/')
		{
			tmp = (!home) ? ft_strdup(cmd + 1) : ft_strjoin(home, cmd + 1);
			free(cmd);
			return (tmp);
		}
	}
	return (cmd);
}

char		**check_tilde(char **cmd, t_list *env)
{
	int		i;

	i = 0;
	if (!cmd)
		return (NULL);
	while (cmd[i])
	{
		cmd[i] = format_tilde(check_quote(cmd[i]), env);
		i++;
	}
	return (cmd);
}

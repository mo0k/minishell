/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tilde.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:13:49 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:17:58 by jmoucade         ###   ########.fr       */
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
		cmd[i] = format_tilde(cmd[i], env);
		i++;
	}
	return (cmd);
}

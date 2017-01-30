/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:13:18 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 18:13:51 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int				do_exec(t_list *environ, t_cmd cmd)
{
	int			status;
	char		**env;

	status = 1;
	if (!environ)
		ft_putstr("\e[31mNo environnement defined.\e[0m\n");
	cmd = get_binpath(get_env(environ, "PATH"), cmd.opts, environ);
	if (!(cmd.path) && cmd.opts)
	{
		if (access(cmd.opts[0], 0) == -1)
		{
			if (ft_strchr(cmd.opts[0], '/'))
				puterror(PROMPT, cmd.opts[0], ERR_NOENT);
			else
				puterror(PROMPT, cmd.opts[0], ERR_NOTFOUND);
		}
	}
	else
	{
		env = transfert_env(environ);
		status = do_fork(cmd.path, cmd.opts, env);
		ft_delstrtab(env);
		free(cmd.path);
	}
	return ((status > 0) ? 1 : 0);
}

int				do_fork(char *binpath, char **av, char **env)
{
	pid_t		pid;
	int			status;

	status = 1;
	while ((pid = fork()) == -1)
		sleep(2);
	if (pid == 0)
	{
		execve(binpath, av, env);
		exit(EXIT_SUCCESS);
	}
	if (pid > 0)
	{
		wait(&status);
	}
	return ((status > 0) ? 1 : 0);
}

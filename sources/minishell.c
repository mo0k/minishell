/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:31:53 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 15:09:57 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int do_exec(t_list *environ, t_cmd cmd)
{
	pid_t 		pid;

	if (!environ)
		ft_putstr("\e[31mNo environnement defined.\e[0m\n");
	cmd = get_path(get_env(environ, "PATH"), cmd.opts, environ);
	if (!(cmd.path))
	{
		if (cmd.opts)
		{
			ft_putstr(cmd.opts[0]);
			ft_putstr(": command not found\n");
		}
	}
	else
	{
		while ((pid = fork()) == -1)
			sleep(2);
		if (pid == 0)
		{
			int test = execve(cmd.path, cmd.opts, NULL);
			printf("ret cmd:%d\n", test);
			ft_putstr("avant fin du pross\n");
			sleep(5);
			exit(EXIT_SUCCESS);
		}
		if (pid > 0)
		{
			wait(NULL);
		}
		free(cmd.path);
	}
	return(1);
}

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmd 		cmd;
	char 		*line;
	t_list 		*environ;
	t_list 		*builtins;

	if (!(environ = env_to_lst(env)))
		return (1);
	if (!(builtins = init_builtins()))
		return (1);
	while (42)
	{
		ft_putstr("\e[31mminish3ll_$> \e[0m");
		get_next_line(0, &line);
		cmd.opts = (*line != 0) ? ft_strsplit(line, ' ') : NULL;
		if (cmd.opts)
			cmd.opts = check_tilde(cmd.opts, environ);
		free(line);
		if (cmd.opts && (is_builtins(builtins, cmd.opts[0])))
			md.ret = do_builtin(&environ, builtins, cmd);
		else
			do_exec(environ, cmd);
		ft_delstrtab(cmd.opts);
	}
	return (0);
}

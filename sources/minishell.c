/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:31:53 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/25 23:57:54 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_cmd 		cmd;
	char 		*line;
	t_list		*environ;
	t_list		*builtins;
	char		**cmdlist;

	if (!(environ = env_to_lst(env)))
		return (1);
	if (!(builtins = init_builtins()))
		return (1);
	while (42)
	{
		ft_putstr(PROMPT);
		get_next_line(0, &line);
		cmdlist = (*line != 0) ? ft_strsplit(line, ';') : NULL ;
		free(line);
		char **tmp = cmdlist;
		while (cmdlist && *cmdlist)
			cmd = do_command(cmd, cmdlist++, environ, builtins);
		ft_delstrtab(tmp);
	}
	return (0);
}

t_cmd do_command(t_cmd cmd, char **cmdlist, t_list *environ, t_list *builtins)
{
	cmd.opts = (**cmdlist != 0) ? ft_strsplit(*cmdlist, ' ') : NULL;
	if (cmd.opts)
		cmd.opts = check_tilde(cmd.opts, environ);
	//free(line);
	if (cmd.opts && (is_builtins(builtins, cmd.opts[0])))
		cmd.ret = do_builtin(&environ, builtins, cmd);
	else
		do_exec(environ, cmd);
	ft_delstrtab(cmd.opts);
	return (cmd);
}
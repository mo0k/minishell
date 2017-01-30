/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:31:53 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 09:27:29 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_cmd	do_cmd(t_cmd cmd, char **cmdlist, t_list *env, t_list *builtins)
{
	cmd.opts = (**cmdlist != 0) ? ft_strsplit(*cmdlist, ' ') : NULL;
	if (cmd.opts)
		cmd.opts = check_tilde(cmd.opts, env);
	if (cmd.opts && (is_builtins(builtins, cmd.opts[0])))
		cmd.ret = do_builtin(&env, builtins, cmd);
	else
		cmd.ret = do_exec(env, cmd);
	ft_delstrtab(cmd.opts);
	return (cmd);
}

static t_cmd	do_cmds(t_cmd cmd, char **cmdlist, t_list *env, t_list *builtins)
{
	char		**cur;

	cur = cmdlist;
	while (cur && *cur)
		cmd = do_cmd(cmd, cur++, env, builtins);
	return (cmd);
}

int				main(int ac, char **av, char **env)
{
	t_cmd 		cmd;
	char 		*line;
	t_list		*environ;
	t_list		*builtins;
	char		**cmdlist;

	(void)ac;
	(void)av;
	cmd.path = 0;
	cmd.opts = NULL;
	cmd.ret = 0;
	if (!(environ = env_to_lst(env)))
		return (1);
	if (!(builtins = init_builtins()))
		return (1);
	while (42)
	{
		ft_putstr(C_PROMPT);
		get_next_line(0, &line);
		cmdlist = (*line != 0) ? ft_strsplit(line, ';') : NULL ;
		free(line);
		cmd = do_cmds(cmd, cmdlist, environ, builtins);
		ft_delstrtab(cmdlist);
	}
	return (0);
}

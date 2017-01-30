/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:31:53 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 17:41:38 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_cmd	do_cmd(t_cmd cmd, char **cmdlist, t_list **env, t_list *bltins)
{
	cmd.opts = (**cmdlist != 0) ? ft_strsplit(*cmdlist, ' ') : NULL;
	if (cmd.opts)
		cmd.opts = check_tilde(cmd.opts, *env);
	if (cmd.opts && (is_builtins(bltins, cmd.opts[0])))
		cmd.ret = do_builtin(env, bltins, cmd);
	else
		cmd.ret = do_exec(*env, cmd);
	ft_delstrtab(cmd.opts);
	return (cmd);
}

static t_cmd	do_cmds(t_cmd cmd, char **cmdlst, t_list **env, t_list *bltins)
{
	char		**cur;

	cur = cmdlst;
	while (cur && *cur)
		cmd = do_cmd(cmd, cur++, env, bltins);
	return (cmd);
}

int				main(int ac, char **av, char **env)
{
	t_cmd		cmd;
	char		*line;
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
		cmdlist = (*line != 0) ? ft_strsplit(line, ';') : NULL;
		free(line);
		cmd = do_cmds(cmd, cmdlist, &environ, builtins);
		ft_delstrtab(cmdlist);
	}
	return (0);
}

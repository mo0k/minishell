/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 22:47:09 by mo0ky             #+#    #+#             */
/*   Updated: 2017/02/05 00:11:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmd.h>

static void		change_tab_to_space(char *line)
{
	int			i;
	int			state_1;
	int			state_2;

	i = 0;
	state_1 = 0;
	state_2 = 0;
	while (line[i])
	{
		if (line[i] == 9 || line[i] == 32)
		{
			line[i] = 32;
			state_1 = 1;
		}
		else
			state_2 = 1;
		i++;
	}
	if(state_1 && !state_2)
		*line = 0;
}

static t_cmd	exec_cmd(t_cmd cmd, char **cmdlist, t_list **env, t_list *bltins)
{
	cmd.opts = (**cmdlist != 0) ? ft_strsplit(*cmdlist, ' ') : NULL;
	if (cmd.opts)
		cmd.opts = check_tilde(cmd.opts, *env);
	if (cmd.opts && cmd.opts[0] && (is_builtins(bltins, cmd.opts[0])))
		cmd.ret = do_builtin(env, bltins, cmd);
	else if (cmd.opts && cmd.opts[0])
		cmd.ret = do_exec(*env, cmd);
	ft_delstrtab(cmd.opts);
	return (cmd);
}

static t_cmd	exec_cmds(t_cmd cmd, char **cmdlst, t_list **env, t_list *bltins)
{
	char		**cur;

	cur = cmdlst;
	while (cur && *cur)
		cmd = exec_cmd(cmd, cur++, env, bltins);
	return (cmd);
}

t_cmd			exec_request(char *cmdline, t_cmd cmd, t_list **environ, t_list *builtins)
{
	char		**cmdlist;

	change_tab_to_space(cmdline);
	cmdlist = (*cmdline != 0) ? ft_strsplit(cmdline, ';') : NULL;
	free(cmdline);
	cmd = exec_cmds(cmd, cmdlist, environ, builtins);
	ft_delstrtab(cmdlist);
	return (cmd);
}

void			init_cmd(t_cmd *cmd)
{
	cmd->path = 0;
	cmd->opts = NULL;
	cmd->ret = 0;
}
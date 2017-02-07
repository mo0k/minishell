/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 22:47:09 by mo0ky             #+#    #+#             */
/*   Updated: 2017/02/06 19:13:29 by jmoucade         ###   ########.fr       */
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
	if (state_1 && !state_2)
		*line = 0;
}

static t_cmd	exec_cmd(t_cmd cmd, char **cmdlst, t_list **env, t_list *btins)
{
	cmd.opts = (**cmdlst != 0) ? ft_strsplit(*cmdlst, ' ') : NULL;
	if (cmd.opts)
		cmd.opts = check_tilde(cmd.opts, *env);
	if (cmd.opts && cmd.opts[0] && (is_builtins(btins, cmd.opts[0])))
		cmd.ret = do_builtin(env, btins, cmd);
	else if (cmd.opts && cmd.opts[0])
		cmd.ret = do_exec(*env, cmd);
	ft_delstrtab(cmd.opts);
	return (cmd);
}

static t_cmd	exec_cmds(t_cmd cmd, char **cmdlst, t_list **env, t_list *btins)
{
	char		**cur;

	cur = cmdlst;
	while (cur && *cur)
		cmd = exec_cmd(cmd, cur++, env, btins);
	return (cmd);
}

t_cmd			exec_request(char *cmds, t_cmd cmd, t_list **env, t_list *btins)
{
	char		**cmdlist;

	change_tab_to_space(cmds);
	cmdlist = (*cmds != 0) ? ft_strsplit(cmds, ';') : NULL;
	cmd = exec_cmds(cmd, cmdlist, env, btins);
	ft_delstrtab(cmdlist);
	return (cmd);
}

void			init_cmd(t_cmd *cmd)
{
	cmd->path = 0;
	cmd->opts = NULL;
	cmd->ret = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:31:53 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/31 02:01:19 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static t_cmd	do_cmd(t_cmd cmd, char **cmdlist, t_list **env, t_list *bltins)
{
	cmd.opts = (**cmdlist != 0) ? ft_strsplit(*cmdlist, ' ') : NULL;
	ft_putstrtab(cmd.opts);
	if (cmd.opts)
		cmd.opts = check_tilde(cmd.opts, *env);
	if (cmd.opts && cmd.opts[0] && (is_builtins(bltins, cmd.opts[0])))
		cmd.ret = do_builtin(env, bltins, cmd);
	else if (cmd.opts && cmd.opts[0])
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

static void		init_cmd(t_cmd *cmd)
{
	cmd->path = 0;
	cmd->opts = NULL;
	cmd->ret = 0;
}

static void		change_tab_to_space(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 9)
			line[i] = 32;
		i++;
	}
}

int				main(int ac, char **av, char **env)
{
	t_cmd		cmd;
	char		*line;
	t_list		*environ;
	t_list		*builtins;
	char		**cmdlist;

	usage(ac, av);
	init_cmd(&cmd);
	if (!(environ = env_to_lst(env)))
		return (1);
	if (!(builtins = init_builtins()))
		return (1);
	signal(SIGINT, SIG_IGN);
	while (42)
	{
		ft_putstr(C_PROMPT);
		get_next_line(0, &line);
		change_tab_to_space(line);
		cmdlist = (*line != 0) ? ft_strsplit(line, ';') : NULL;
		free(line);
		cmd = do_cmds(cmd, cmdlist, &environ, builtins);
		ft_delstrtab(cmdlist);
	}
	return (0);
}

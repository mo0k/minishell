/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 10:09:07 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/05 01:04:55 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binaries.h>

char			*check_cmd(char *cmd, t_list *env)
{
	char		*new_cmd;

	if (cmd && *cmd == '$')
	{
		if ((new_cmd = get_env(env, cmd + 1)))
		{
			free(cmd);
			return(ft_strdup(new_cmd));
		}
		else
		{
			free(cmd);
			return(ft_strdup(0));
		}
	}
	return (cmd);
}

char			**check_cmds(char **cmd, t_list *env)
{
	int			i;

	i = 0;
	while (cmd[i])
	{
		check_cmd(check_quote(cmd[i]), env);
		i++;
	}
	return (check_tilde(cmd, env));
}

static int		rights_access(char *path)
{
	struct stat	s;

	if (lstat(path, &s) == -1)
		return (0);
	if (S_ISDIR(s.st_mode))
	{
		puterror(PROMPT, path, ERR_DIR);
		return (0);
	}
	else if (access(path, X_OK) == -1)
	{
		puterror(PROMPT, path, ERR_ACCESS);
		return (0);
	}
	return (1);
}

static void		find_binpath(char *envpath, char **cmd, t_list *env, t_cmd *ret)
{
	char		**path_tab;
	char		*path;
	char		**tmp;

	path_tab = (envpath && *envpath == 0) ? NULL : ft_strsplit(envpath, ':');
	tmp = path_tab;
	while (tmp && *tmp)
	{
		if (!(path = ft_strnew(ft_strlen(*tmp) + ft_strlen(*cmd) + 1)))
			return ;
		path = ft_strcpy(path, *tmp);
		path[ft_strlen(*tmp)] = '/';
		path = ft_strcat(path, *cmd);
		if (access(path, 0) == 0)
		{
			if ((rights_access(path)))
				ret->path = ft_strdup(path);
			ret->opts = check_cmds(cmd, env);
		}
		free(path);
		tmp++;
	}
	ft_delstrtab(path_tab);
}

t_cmd			get_binpath(char *env_path, char **cmd, t_list *env)
{
	t_cmd		ret;
	int			result;

	ret.path = NULL;
	ret.opts = cmd;
	ret.ret = 1;
	if (!cmd)
		return (ret);
	if (access(*(cmd), 0) == 0)
	{
		if ((result = rights_access(*cmd)))
			ret.path = ft_strdup(*cmd);
		ret.opts = check_cmds(cmd, env);
		return (ret);
	}
	else
		find_binpath(env_path, cmd, env, &ret);
	return (ret);
}

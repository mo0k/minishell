/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 10:09:07 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 18:57:08 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binaries.h>

char			**check_cmd(char **cmd, t_list *env)
{
	int			i;
	char		*new_cmd;

	i = 0;
	while (cmd[i])
	{
		if (*cmd[i] == '$')
		{
			if ((new_cmd = get_env(env, cmd[i] + 1)))
			{
				free(cmd[i]);
				cmd[i] = ft_strdup(new_cmd);
			}
		}
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
			ret->opts = check_cmd(cmd, env);
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
	if (!env_path || !cmd)
		return (ret);
	if (access(*(cmd), 0) == 0)
	{
		if ((result = rights_access(*cmd)))
			ret.path = ft_strdup(*cmd);
		ret.opts = check_cmd(cmd, env);
		return (ret);
	}
	else
		find_binpath(env_path, cmd, env, &ret);
	return (ret);
}

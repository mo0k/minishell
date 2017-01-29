/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 10:09:07 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/29 22:15:12 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <binaries.h>

char **check_cmd(char **cmd, t_list *env)
{
	int i;
	char *new_cmd;

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

static int rights_access(char *path)
{
	struct stat s;

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

static void find_binpath(char *env_path, char **cmd, t_list *env, t_cmd *ret)
{
	char **path_tab;
	char *path;

	path_tab = ft_strsplit(env_path, ':');
	char **tmp = path_tab;
	while (*tmp)
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

t_cmd get_binpath(char *env_path, char **cmd, t_list *env)
{
	t_cmd ret;

	ret.path = NULL;
	ret.opts = cmd;
	ret.ret = 0;
	if (!env_path || !cmd)
		return (ret);
	if (access(*(cmd), 0) == 0) 
	{
		int result;
		if ((result = rights_access(*cmd)))
			ret.path = ft_strdup(*cmd);
		//printf("avant crash 1=> ret:%d\n", result);
		ret.opts = check_cmd(cmd, env);
		//ft_putstr(ret.path);
		//write(1, "\n", 1);
		//ft_putstrtab(ret.opts);
		return (ret);
	}
	else
		find_binpath(env_path, cmd, env, &ret);
	return (ret);
}

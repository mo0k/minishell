/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 14:13:18 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:15:56 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char **check_cmd(char **cmd, t_list *env)
{
	int i;
	char *new_cmd;

	i = 0;
	while (cmd[i])
	{
		if (*cmd[i] == '$')
		{
			printf("check_cmd:%s\n", get_env(env, cmd[i] + 1));
			if ((new_cmd = get_env(env, cmd[i] + 1)))
			{
				free(cmd[i]);
				cmd[i] = ft_strdup(new_cmd);
				//ft_putstr(ft_strchr(new_cmd, '=') + 1);
			}
		}
		i++;
	}
	//return (cmd);
	return (check_tilde(cmd, env));
}

t_cmd get_path(char *env_path, char **cmd, t_list *env)
{
			printf("start get_path\n");
	char **path_tab;
	char *path;
	t_cmd ret;
	//ret = NULL;
	ret.path = NULL;
	ret.opts = cmd;
	ret.ret = 0;
	if (!env_path || !cmd)
	{
		printf("fuck off\n");
		return (ret);
	}
	//env_path+=5;
	if (access(*(cmd), 0) == 0)
	{
		ret.path = ft_strdup(*cmd);
			printf("avant crash 1\n");
		ret.opts = check_cmd(cmd, env);
		return (ret);;
	}
	path_tab = ft_strsplit(env_path, ':');
	char **tmp = path_tab;
	while (*tmp)
	{
		//printf("in while\n");
		if (!(path = ft_strnew(ft_strlen(*tmp) + ft_strlen(*cmd) + 1)))
			return (ret);
		path = ft_strcpy(path, *tmp);
		path[ft_strlen(*tmp)] = '/';
		path = ft_strcat(path, *cmd);
		if (access(path, 0) == 0)
		{
			//ret = (t_cmd*)malloc(sizeof(t_cmd));
			ret.path = path;
			printf("avant crash 2\n");
			ret.opts = check_cmd(cmd, env);
			//printf("yo\n");
			ft_delstrtab(path_tab);
			//delete path_tab;
			//printf("fin get_path\n");
			return (ret);
		}
		free(path);
		tmp++;
	}
	
	//printf("aavnt free\n");
	ft_delstrtab(path_tab);

	return (ret);
}
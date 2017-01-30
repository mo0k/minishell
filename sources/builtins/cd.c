/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:55:57 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:32:39 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

static void		chdir_authorized(char *path, char *old_pwd_value, t_list **env)
{
	t_cmd		new;
	t_cmd		old;
	char		*new_pwd;
	char		*old_pwd;

	if (!(old_pwd = ft_strjoin("OLDPWD=", old_pwd_value)))
		return ;
	if (!(old.opts = ft_strsplit(old_pwd, ' ')))
	{
		free(old_pwd);
		return ;
	}
	free(old_pwd);
	ft_setenv(env, old);
	ft_delstrtab(old.opts);
	if (!(new_pwd = ft_strjoin("PWD=", getcwd(path, CWD))))
		return ;
	if (!(new.opts = ft_strsplit(new_pwd, ' ')))
	{
		free(new_pwd);
		return ;
	}
	free(new_pwd);
	ft_setenv(env, new);
	ft_delstrtab(new.opts);
}

static int		chdir_refused(char *pathdir)
{
	struct stat	s;

	if ((lstat(pathdir, &s)) == -1)
		puterror("cd", pathdir, ERR_NOENT);
	else if (!S_ISDIR(s.st_mode))
		puterror("cd", pathdir, ERR_NOTDIR);
	else if (access(pathdir, X_OK) == -1)
		puterror("cd", pathdir, ERR_ACCESS);
	return (1);
}

int				ft_cd(t_list **env, t_cmd command)
{
	char		*path;
	char		*old_pwd_value;
	int			ret;
	char		**cmd;

	path = ft_strnew(CWD);
	cmd = check_cmd(command.opts + 1, *env);
	ret = 0;
	old_pwd_value = getcwd(path, CWD);
	if (!*cmd || **cmd == '$')
	{
		if (chdir(get_env(*env, "HOME")) == -1)
			ret = chdir_refused(*cmd);
		else
			chdir_authorized(path, old_pwd_value, env);
	}
	else
	{
		if (chdir(*cmd) == -1)
			ret = chdir_refused(*cmd);
		else
			chdir_authorized(path, old_pwd_value, env);
	}
	free(path);
	return (ret);
}

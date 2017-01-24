/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:55:57 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:03:36 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int 	ft_cd(t_list 	**env, t_cmd command)
{
	printf("IN CD\n");
	char *path = ft_strnew(255);
	//char pwd[4];
	char *new_pwd;
	char *old_pwd;
	char *old_pwd_value;

	char **cmd;
	cmd = command.opts + 1;

	old_pwd_value = (!get_env(*env, "PWD")) ? NULL : get_env(*env, "PWD")+4;
	if (!*cmd)
	{

		if (chdir((!get_env(*env, "HOME")) ? NULL : get_env(*env, "HOME") + 5) == -1)
		{
			ft_putstr("Erreur changement de dossier");
			free(path);
			return (1);
		}
		else
		{
			t_cmd new;
			new_pwd = ft_strjoin("PWD=", getcwd(path, 255));
			new.opts = ft_strsplit(new_pwd, ' ');
			t_cmd old;
			old_pwd = ft_strjoin("OLDPWD=", old_pwd_value);
			old.opts = ft_strsplit(old_pwd, ' ');
			ft_setenv(env, old);
			ft_setenv(env, new); //PWD=cmd
			free(old_pwd);
			free(new_pwd);
			ft_delstrtab(new.opts);
			ft_delstrtab(old.opts);
		}
	}
	else
	{
		printf("par la\n");
		if (chdir(*cmd) == -1)
		{
			ft_putstr("Erreur changement de dossier");
			free(path);
			return (1);
		}
		else
		{
			t_cmd new;
			new_pwd = ft_strjoin("PWD=", getcwd(path, 255));
			new.opts = ft_strsplit(new_pwd, ' ');
			t_cmd old;
			old_pwd = ft_strjoin("OLDPWD=", old_pwd_value);
			old.opts = ft_strsplit(old_pwd, ' ');
			ft_setenv(env, old);
			ft_setenv(env, new); //PWD=cmd
			free(old_pwd);
			free(new_pwd);
			ft_delstrtab(new.opts);
			ft_delstrtab(old.opts);
		}
	}
	free(path);
	return (0);
}

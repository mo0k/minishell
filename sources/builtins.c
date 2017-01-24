/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 09:58:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 13:57:44 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

char			**get_builtins_name(void)
{
	char		**builtins_name;

	if (!(builtins_name = (char**)malloc(sizeof(char*) * (NBR_BUILTINS + 1))))
		return (NULL);
	builtins_name[NBR_BUILTINS + 1] = NULL;
	builtins_name[0] = ft_strdup("printenv");
	builtins_name[1] = ft_strdup("exit");
	builtins_name[2] = ft_strdup("unsetenv");
	builtins_name[3] = ft_strdup("echo");
	builtins_name[4] = ft_strdup("env");
	builtins_name[5] = ft_strdup("clearenv");
	builtins_name[6] = ft_strdup("setenv");
	builtins_name[7] = ft_strdup("cd");
	return (builtins_name);
}

void			**get_builtins_func(void)
{
	void		**builtins_func;

	if (!(builtins_func = (void**)malloc(sizeof(void*) * (NBR_BUILTINS + 1))))
		return (NULL);
	builtins_func[NBR_BUILTINS + 1] = NULL;
	builtins_func[0] = &printenv;
	builtins_func[1] = &exit_prog;
	builtins_func[2] = &ft_unsetenv;
	builtins_func[3] = &echo;
	builtins_func[4] = &printenv;
	builtins_func[5] = &ft_clearenv;
	builtins_func[6] = &ft_setenv;
	builtins_func[7] = &ft_cd;
	return (builtins_func);
}

t_list			*init_builtins(void)
{
	int			i;
	char		**builtins_name;
	void		**builtins_func;
	t_list		*lst_builtins;
	t_builtins	builtin;

	i = 0;
	builtins_name = get_builtins_name();
	builtins_func = get_builtins_func();
	lst_builtins = NULL;
	while (builtins_name[i] && builtins_func[i])
	{
		builtin.name = ft_strdup(builtins_name[i]);
		builtin.func = builtins_func[i];
		ft_lstadd_start(&lst_builtins, ft_lstnew(&builtin, sizeof(t_builtins)));
		i++;
	}
	free(builtins_func);
	ft_delstrtab(builtins_name);
	return (lst_builtins);
}

int 			is_builtins(t_list *builtins, char *command)
{
	t_list		*cur;

	cur = builtins;
	while (cur)
	{
		if (!ft_strcmp(((t_builtins*)(cur->content))->name, command))
			return (1);
		cur = cur->next;
	}
	return (0);
}

int				do_builtin(t_list **environ, t_list *builtins, t_cmd cmd)
{
	t_list		*tmp_bltins;

	tmp_bltins = builtins;
	while (tmp_bltins)
	{
		if (!ft_strncmp(((t_builtins*)(tmp_bltins->content))->name, cmd.opts[0], ft_strlen(cmd.opts[0])))
		{
			return ((((t_builtins*)(tmp_bltins->content))->func)(environ, cmd));
		}
		tmp_bltins = tmp_bltins->next;
	}
	return (0);
}

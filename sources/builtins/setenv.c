/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:43:37 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 17:33:37 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

static int	modif_env(t_list *select, char *value, t_list *env)
{
	free(((t_env*)(select->content))->value);
	((t_env*)(select->content))->value = format_tilde(ft_strdup(value), env);
	return (0);
}

static int	add_env(char *value, t_list **env)
{
	t_env	elem;

	if (!(elem.key = ft_strsub(value, 0, ft_strchr(value, '=') - value)))
		return (1);
	elem.value = format_tilde(ft_strdup(ft_strchr(value, '=') + 1), *env);
	ft_lstadd_end(env, ft_lstnew(&elem, sizeof(t_env)));
	return (0);
}

int			ft_setenv(t_list **env, t_cmd command)
{
	char	*sign;
	t_list	*tmp;
	char	**cmd;

	if (!env || !command.opts)
		return (1);
	cmd = (*(command.opts + 1)) ? command.opts + 1 : command.opts;
	if ((sign = ft_strrchr(*cmd, '=')) && ft_strlen(*cmd) > 1 &&
		sign != *cmd && sign != *cmd + ft_strlen(*cmd))
	{
		*sign = 0;
		if ((tmp = ft_lstselect(env, *cmd, &select_env)))
			return (modif_env(tmp, sign + 1, *env));
		else
		{
			*sign = '=';
			return (add_env(*cmd, env));
		}
	}
	return (1);
}

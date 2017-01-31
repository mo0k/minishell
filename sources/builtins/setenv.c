/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:43:37 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/31 00:21:12 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

static int	add_env(char *key, char *value, t_list **env)
{
	t_list	*tmp;
	t_env	elem;

	if ((tmp = ft_lstselect(env, key, &select_env)))
	{
		free(((t_env*)(tmp->content))->value);
		((t_env*)(tmp->content))->value = format_tilde(ft_strdup(value), *env);
		return (0);
	}
	else
	{
		if (!(elem.key = ft_strdup(key)))
			return (1);
		elem.value = format_tilde(ft_strdup(value), *env);
		ft_lstadd_end(env, ft_lstnew(&elem, sizeof(t_env)));
		return (0);
	}
}

static int	is_quote(char *str)
{
	if (str && *str == 34 && str[ft_strlen(str) - 1] == 34)
		return (1);
	else if (str && *str == 39 && str[ft_strlen(str) - 1] == 39)
		return (1);
	return (0);
}

static int	do_setenv(t_list **env, char *cmd)
{
	char	*sign;
	char	*value;
	int		ret;

	if ((sign = ft_strrchr(cmd, '=')) && ft_strlen(cmd) > 1 &&
				sign != cmd && sign != cmd + ft_strlen(cmd))
	{
		*sign = 0;
		if (is_quote(sign + 1))
		{
			value = sign + 2;
			value[ft_strlen(value) - 1] = 0;
		}
		else
			value = sign + 1;
		ret = add_env(cmd, value, env);
	}
	else
		ret = 1;
	return (ret);
}

int			ft_setenv(t_list **env, t_cmd command)
{
	char	**cmd;
	int		ret;

	if (!env || !command.opts)
		return (1);
	ret = 1;
	cmd = (*(command.opts + 1)) ? command.opts + 1 : command.opts;
	while (*cmd)
	{
		ret = do_setenv(env, *cmd);
		cmd++;
	}
	return (ret);
}

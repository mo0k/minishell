/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 23:43:37 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:05:37 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int	ft_setenv(t_list 	**env, t_cmd command)
{
	char *sign;
	t_list *tmp;
	t_env 	elem;

	if (!env || !command.opts)
		return (1);

	char **cmd;
	cmd = (*(command.opts + 1)) ? command.opts + 1: command.opts;
	printf("%p\n", cmd);
	if ((sign = ft_strrchr(*cmd, '=')) && ft_strlen(*cmd) > 1 &&
		sign != *cmd && sign != *cmd + ft_strlen(*cmd))
	{
		//printf("OKKKKKK\t%s\n", *cmd);
		//if (!(elem = (t_env*)malloc(sizeof(t_env))))
		//	return ;
		//if (is_exist(env, *cmd))
		//	return ;
		*sign = 0;
		if((tmp = ft_lstselect(env, *cmd, &select_env)))
		{
			free(((t_env*)(tmp->content))->value);
			((t_env*)(tmp->content))->value = format_tilde(ft_strdup(sign + 1), *env);
		}
		else
		{
			printf("yoooooo\n");
			*sign = '=';
			elem.key = ft_strsub(*cmd, 0, ft_strchr(*cmd, '=') - *cmd);
			elem.value = format_tilde(ft_strdup(ft_strchr(*cmd, '=')+1), *env);
			ft_lstadd_end(env, ft_lstnew(&elem, sizeof(t_env)));
		}
	}
	return (0);
}

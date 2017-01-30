/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:38:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 10:14:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

char			*get_env(t_list *env, char *variable)
{
	t_list		*cur;

	cur = env;
	while (cur)
	{
		if (!ft_strcmp(variable, ((t_env *)(cur->content))->key))
			return (((t_env *)(cur->content))->value);
		cur = cur->next;
	}
	return (NULL);
}

t_list *env_to_lst(char  **env)
{
	t_list 	*lst_env;
	t_env 	elem;

	lst_env = NULL;
	while (*env)
	{
		elem.key = ft_strsub(*env, 0, ft_strchr(*env, '=') - *env);
		elem.value =  ft_strdup(ft_strchr(*env, '=')+1);
		ft_lstadd_start(&lst_env, ft_lstnew(&elem, sizeof(t_env)));
		env++;
	}
	ft_lstrev(&lst_env);
	return (lst_env);
}

char			**transfert_env(t_list *env)
{
	printf("IN transfert env\n");
	int			len;
	char		**new_env;
	int			i;
	t_list		*cur;

	len = ft_lstlen(env);
	if (!env || (len == 0))
		return (NULL);
	i = 0;
	printf("len:%d\n", len);
	cur = env;
	new_env = (char**)malloc(sizeof(char*) * (len + 1));
	new_env[len] = NULL;
	while (cur)
	{	
		printf("DEBUG:%s=%s\n", ((t_env*)(cur->content))->key, ((t_env*)(cur->content))->value);
		new_env[i++] = ft_strtriplejoin(((t_env*)(cur->content))->key, "=", \
										((t_env*)(cur->content))->value);
		cur = cur->next;
	}
	ft_putstrtab(new_env);
	return (new_env);
}
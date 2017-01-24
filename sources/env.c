/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:38:56 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:04:57 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

char *get_env(t_list *env, char *variable)
{
	t_list *cur;

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



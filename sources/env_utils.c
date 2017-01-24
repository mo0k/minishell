/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 13:39:04 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 14:05:29 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <env.h>

void del_env(void *env, size_t size)
{
	(void)size;

	if (!env)
		return ;
	free(((t_env*)(env))->key);
	free(((t_env*)(env))->value);
	((t_env*)(env))->key = NULL;
	((t_env*)(env))->value = NULL;
	free(env);
	env = NULL;
}

int 	select_env(t_list *env, char *var)
{
	if (!env)
		return (0);
	if (!ft_strcmp(var, ((t_env *)(env->content))->key))
		return (1);
	return (0);
}

void display_all(t_list *env)
{
	//printf("%p\t%p\t%p\t%s=%s\n", env, env->next, env->prev, ((t_env *)(env->content))->key, ((t_env *)(env->content))->value);
	ft_putstr(((t_env *)(env->content))->key);
	write(1, "=", 1);
	ft_putstr(((t_env *)(env->content))->value);
	write(1, "\n", 1);
}

void display(t_list *env)
{
	ft_putstr(((t_env *)(env->content))->value);
	write(1, "\n", 1);
}

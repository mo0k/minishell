/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:09:29 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 13:57:46 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

int	ft_unsetenv(t_list **env, t_cmd command)
{
	printf("STARTT UNSETENV: %p\n", *env);
	t_list *cur;
	//char *ptr;
	char **cmd;

	cmd = command.opts + 1;
	cur = *env;
	if (!*cmd || !*env)
		return (1);
	
	while (cur)
	{
		printf("%p\t%p\t%p\t%s\t%s\n", cur, cur->next, cur->prev, ((t_env *)(cur->content))->key, ((t_env *)(cur->content))->value);
		//ptr = ft_strchr(((t_env *)(cur->content))->var, '=');
		//if ((long)ft_strlen(*cmd) == ptr - ((t_env *)(cur->content))->var &&
		//	!ft_strncmp(((t_env*)(cur->content))->var, *cmd, ft_strlen(*cmd)))
		if (!ft_strcmp(*cmd, ((t_env*)(cur->content))->key))
		{
				printf("Avant supp\n");
				if (cur == *env)
				{
					printf("delfirst\n");
					ft_lstdelfirst(env, &del_env);
				}
				else
				{
					printf("delnext\n");
					ft_lstdelnext(&cur->prev, &del_env);
				}
				printf("Apres supp\n");
				return (0);
		}
		cur = cur->next;
	}
	return (1);
}
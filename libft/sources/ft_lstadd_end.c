/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:44:06 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/24 11:01:49 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		ft_lstadd_end(t_list **alst, t_list *new)
{
	t_list	*prev;
	t_list	*cur;

	prev = NULL;
	cur = *alst;
	if (!new)
		return ;
	if (!*alst)
	{
		ft_lstadd_start(alst, new);
		return ;
	}
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->prev = prev;
	new->next = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 20:53:17 by jmoucade          #+#    #+#             */
/*   Updated: 2016/12/12 00:40:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_addchar(char **dst, char c)
{
	char	*tmp;
	int		len;

	if (!dst)
		return (0);
	if (!*dst)
	{
		if (!(*dst = ft_strnew(1)))
			return (0);
		**dst = c;
	}
	else
	{
		len = (int)ft_strlen(*dst);
		if (!(tmp = ft_strnew(len + 1)))
			return (0);
		tmp = ft_strcpy(tmp, *dst);
		tmp[len] = c;
		free(*dst);
		if (!(*dst = ft_strdup(tmp)))
			return (0);
		free(tmp);
	}
	return (1);
}
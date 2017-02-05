/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 00:51:45 by mo0ky             #+#    #+#             */
/*   Updated: 2017/02/05 01:15:16 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <quote.h>

static int		new_string(char **str, int len)
{
	char		*tmp;

	if (!str || !*str)
		return (0);
	tmp = *str;
	*(tmp + len - 1) = 0;
	free(*str);
	*str = ft_strdup(tmp + 1);
	return (1);
}

char			*check_quote(char *str)
{
	int			len;

	if (str && (*str == 34 || *str == 39) && (len = ft_strlen(str)))
	{
		if ((*str == 34 && *(str + len - 1) == 34) || 
			(*str == 39 && *(str + len - 1) == 39))
			new_string(&str, len);
	}
	return (str);
}
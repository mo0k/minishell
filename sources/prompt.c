/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:14:11 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/31 16:14:53 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_last_dir(char *pathdir)
{
	char *a;

	return (((a = ft_strrchr(pathdir, '/')) && !*(a + 1)) ? pathdir : a + 1);
}

void		prompt(void)
{
	char	*currentdir;

	currentdir = getcwd(NULL, CWD);
	if (currentdir)
	{
		ft_putstr(PROMPT_COLOR);
		ft_putstr(get_last_dir(currentdir));
		ft_putstr(NOCOLOR);
		ft_putstr(SYMBOL_COLOR);
		ft_putstr("_$>");
		ft_putstr(NOCOLOR);
	}
	else
		ft_putstr(C_PROMPT);
	free(currentdir);
}

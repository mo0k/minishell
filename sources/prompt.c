/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:14:11 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/04 22:42:15 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
/*
static char	*get_last_dir(char *pathdir)
{
	char *a;

	return (((a = ft_strrchr(pathdir, '/')) && !*(a + 1)) ? pathdir : a + 1);
}
*/
int			prompt(void)
{
	char	*currentdir;

	currentdir = getcwd(NULL, CWD);
	if (currentdir)
	{
		ft_putstr(PROMPT_COLOR);
		//ft_putstr(get_last_dir(currentdir));
		ft_putstr(currentdir);
		ft_putstr(NOCOLOR);
		ft_putstr(SYMBOL_COLOR);
		ft_putstr(" > ");
		ft_putstr(NOCOLOR);
	}
	else
		ft_putstr(C_PROMPT);
	free(currentdir);
	return (1);
}

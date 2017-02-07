/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:14:11 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/06 14:44:20 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int			prompt(void)
{
	char	*currentdir;

	currentdir = getcwd(NULL, CWD);
	if (currentdir)
	{
		ft_putstr(PROMPT_COLOR);
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

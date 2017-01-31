/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:32:51 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/31 14:59:57 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void		handler_prompt(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	ft_putstr(C_PROMPT);
}

void		handler_noprompt(int signo)
{
	write(1, "\n", 1);
	signal(signo, SIG_DFL);
}

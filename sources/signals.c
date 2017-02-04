/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:32:51 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/04 22:30:37 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signals.h>

void		signal_handler(void (*handler)(int))
{
	int		i;

	i = 1;
	while (i < NBR_SIG)
	{
		signal(i, handler);
		i++;
	}
}

void		handler_prompt(int signo)
{
	if (signo == SIGINT)
	{
		write(1, "\n", 1);
		prompt();
	}
}

void		handler_noprompt(int signo)
{
	if (signo == SIGINT)
		write(1, "\n", 1);
}

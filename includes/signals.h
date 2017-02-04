/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:33:34 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/04 01:50:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

# include <minishell.h>

# define NBR_SIG 32

void		signal_handler(void (*f)(int));
void		handler_prompt(int signo);
void		handler_noprompt(int signo);

#endif

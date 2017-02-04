/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:24:16 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/04 23:06:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H



# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <libft.h>
# include <get_next_line.h>
# include <types.h>
# include <signals.h>
# include <tilde.h>
# include <env.h>
# include <builtins.h>
# include <cmd.h>
# include <binaries.h>
# include <error.h>
# include <color.h>

# define CWD 255
# define PROMPT "minish3ll"
# define PROMPT_COLOR GREEN
# define SYMBOL_COLOR CYAN
# define C_PROMPT PROMPT_COLOR PROMPT"_$> "NOCOLOR

void		usage(int ac, char **av);
int			prompt(void);

#endif

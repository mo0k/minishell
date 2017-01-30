/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:24:16 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 08:54:46 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <libft.h>
# include <get_next_line.h>
# include <types.h>
# include <tilde.h>
# include <env.h>
# include <builtins.h>
# include <binaries.h>
# include <error.h>
# include <color.h>

# define PROMPT "minish3ll"
# define COLOR_PROMPT YELLOW
# define PROMPT_COLOR COLOR_PROMPT PROMPT"_$> "NOCOLOR

t_cmd			do_command(t_cmd cmd, char **cmdlist, t_list *environ, t_list *builtins);

#endif
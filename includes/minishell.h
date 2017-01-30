/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:24:16 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:27:14 by jmoucade         ###   ########.fr       */
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
# define PROMPT_COLOR YELLOW
# define C_PROMPT PROMPT_COLOR PROMPT"_$> "NOCOLOR

#endif

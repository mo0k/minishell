/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 00:24:16 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 00:04:01 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_cmd
{
				char *path;
				char **opts;
				int ret;
}				t_cmd;

typedef struct 	s_env
{
				char *key;
				char *value;
}				t_env;

# include <unistd.h>
# include <stdio.h>
# include <libft.h>
# include <get_next_line.h>
# include <tilde.h>
# include <env.h>
# include <builtins.h>
# include <binaries.h>
# include <error.h>

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"

# define PROMPT "minish3ll"
# define COLOR YELLOW
# define NOCOLOR "\e[0m"
# define PROMPT_COLOR COLOR PROMPT"_$> "NOCOLOR

t_cmd			do_command(t_cmd cmd, char **cmdlist, t_list *environ, t_list *builtins);

#endif
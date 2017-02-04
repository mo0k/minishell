/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 21:31:53 by jmoucade          #+#    #+#             */
/*   Updated: 2017/02/05 00:11:08 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int				main(int ac, char **av, char **env)
{
	t_cmd		cmd;
	char		*line;
	t_list		*environ;
	t_list		*builtins;

	usage(ac, av);
	init_cmd(&cmd);
	if (!(environ = env_to_lst(env)))
		return (1);
	if (!(builtins = init_builtins()))
		return (1);
	signal_handler(&handler_prompt);
	while (42)
	{
		if (prompt() && get_next_line(0, &line) == 1)
			cmd = exec_request(line, cmd, &environ, builtins);
		else
			write(1, "\n", 1);
	}
	return (0);
}

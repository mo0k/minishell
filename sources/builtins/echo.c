/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:07:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/29 23:55:29 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <builtins.h>

static void	print_space(int state)
{
	if (state)
		write(1, " ", 1);
}

static int echo_return(int ret, int state)
{
	print_space(state);
	ft_putnbr(ret);
	return (1);
}

static int echo_env(t_list 	**env, char *cmd, int state)
{
	char *str;

	if ((str = get_env(*env, cmd)))
	{
		print_space(state);
		ft_putstr(str);
		state = ((str && *str == 0)) ? 0 : 1;
	}
	return (state) ? (1) : (0);
}

int	echo(t_list 	**env, t_cmd command)
{
	int state;
	char **cmd;

	state = 0;
	if (!command.opts)
		return (1);
	cmd = command.opts + 1;
	while (*cmd)
	{
		if (!ft_strcmp(*cmd, "$?"))
			state = echo_return(command.ret, state);
		else if (**cmd == '$')
			state = echo_env(env, *cmd+1, state);
		else
		{
			print_space(state);
			ft_putstr(*cmd);
			state = 1;
		}
		cmd++;
	}
	write(1, "\n", 1);
	return (0);
}
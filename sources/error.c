/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:31:30 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/29 14:45:53 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>

void puterror(char *command, char *path, char *error)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

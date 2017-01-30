/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:31:30 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:14:53 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <error.h>

void	puterror(char *command, char *path, char *error)
{
	ft_putstr_fd(command, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(error, 2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 08:53:26 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 16:28:48 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct	s_cmd
{
	char		*path;
	char		**opts;
	int			ret;
}				t_cmd;

typedef struct	s_env
{
	char		*key;
	char		*value;
}				t_env;

#endif

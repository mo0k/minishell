/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 08:53:26 by mo0ky             #+#    #+#             */
/*   Updated: 2017/01/30 08:54:20 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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

#endif
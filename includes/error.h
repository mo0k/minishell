/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 14:31:37 by jmoucade          #+#    #+#             */
/*   Updated: 2017/01/30 17:39:39 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <minishell.h>

# define ERR_NOENT		"No such file or directory"
# define ERR_NOTDIR		"Not a directory"
# define ERR_DIR		"Is a directory"
# define ERR_ACCESS		"Permission denied"
# define ERR_NOTFOUND	"command not found"

void puterror(char *command, char *path, char *error);

#endif

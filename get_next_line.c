/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 10:59:51 by mverbrug      #+#    #+#                 */
/*   Updated: 2021/03/19 12:59:05 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** This function returns a line read from a file descriptor,
** without the newline.
** Returns 1 if a line has been read.
** Returns 0 if EOF has been reached.
** Returns -1 if an error happened.
*/

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			result;
	char		*temp;
	static char	buf[BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	result = 1;
	while (result > 0)
	{
		temp = *line;
		*line = ft_strjoin(temp, buf);
		free(temp);
		if (ft_newline(buf, '\n'))
			return (1);
		result = read(fd, buf, BUFFER_SIZE);
		if (result == -1)
			return (-1);
		buf[result] = '\0';
	}
	if (result == 0)
		return (0);
	return (1);
}

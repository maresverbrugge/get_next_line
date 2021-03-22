/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 14:50:33 by mverbrug      #+#    #+#                 */
/*   Updated: 2021/03/19 12:58:59 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			result;
	char		*temp;
	static char	buf[1024][BUFFER_SIZE + 1];

	if (fd < 0 || fd > 1024 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	*line = NULL;
	result = 1;
	while (result > 0)
	{
		temp = *line;
		*line = ft_strjoin(temp, buf[fd]);
		free(temp);
		if (ft_newline(buf[fd], '\n'))
			return (1);
		result = read(fd, buf[fd], BUFFER_SIZE);
		if (result == -1)
			return (-1);
		buf[fd][result] = '\0';
	}
	if (result == 0)
		return (0);
	return (1);
}

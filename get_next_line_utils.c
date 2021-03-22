/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/22 11:50:21 by mverbrug      #+#    #+#                 */
/*   Updated: 2021/03/19 11:20:04 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_strcpy(char *dst, const char *src)
{
	int	i;

	if (!src || !dst)
		return ;
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

int	ft_newline(char *s, int c)
{
	char	*str;

	str = s;
	while (*str)
	{
		if (*str == c)
		{
			ft_strcpy(s, str + 1);
			return (1);
		}
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*joined;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	if (!s1 || !s2)
		len_s1 = 0;
	else
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = malloc(len_s1 + len_s2 + 1);
	if (!joined)
		return (NULL);
	ft_strcpy(joined, s1);
	i = 0;
	while (i < len_s2 && s2[i] != '\n')
	{
		joined[len_s1 + i] = s2[i];
		i++;
	}
	joined[len_s1 + i] = '\0';
	return (joined);
}

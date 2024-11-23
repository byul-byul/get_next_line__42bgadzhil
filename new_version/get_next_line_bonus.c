/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:49 by bhajili           #+#    #+#             */
/*   Updated: 2024/11/23 21:44:13 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ready_for_next(char *line)
{
	char	*next;
	char	*ptr;
	int		len;

	ptr = ft_strchr(line, '\n');
	if (!ptr)
	{
		return (free(line), NULL);
	}
	else
		len = (ptr - line) + 1;
	if (!line[len])
		return (free(line), NULL);
	next = ft_strchr_allocation(line, len);
	free (line);
	if (!next)
		return (NULL);
	return (next);
}

char	*clean_line(char *line)
{
	char	*clean_line;

	if (!ft_strchr(line, '\n'))
	{
		clean_line = ft_strchar_rev(line, '\0');
		if (!clean_line)
			return (NULL);
		return (clean_line);
	}
	clean_line = ft_strchar_rev(line, '\n');
	if (!clean_line)
		return (NULL);
	return (clean_line);
}

char	*read_line(char *line, int fd)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(line), line = NULL, NULL);
	buffer[0] = '\0';
	while (read_bytes > 0 && !ft_strchr(line, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buffer[read_bytes] = '\0';
			line = ft_strjoin(line, buffer);
		}
	}
	free(buffer);
	if (read_bytes < 0 || !line)
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[MAX_FD];
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!line[fd] || (line[fd] && !ft_strchr(line[fd], '\n')))
		line[fd] = read_line(line[fd], fd);
	if (!line[fd])
		return (NULL);
	new_line = clean_line(line[fd]);
	if (!new_line || ft_strlen(new_line) == 0)
		return (free(line[fd]), line[fd] = NULL, free(new_line), NULL);
	line[fd] = ready_for_next(line[fd]);
	return (new_line);
}

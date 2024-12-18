/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:49 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/18 12:11:47 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr_allocation(char *line, int len)
{
	char	*line_a;
	int		i;

	line_a = malloc(sizeof(char) * (ft_strlen(line) - len + 1));
	if (!line_a)
		return (NULL);
	i = 0;
	while (line[len])
	{
		line_a[i++] = line[len++];
	}
	line_a[i] = '\0';
	return (line_a);
}

//static char	*clean_buff(char *buff)
//{
//	char	*next;
//	size_t	len;
//	char	*pos;

//	pos = ft_strchr(buff, SEPARATOR);
//	if (pos)
//		len = pos - buff + 1;
//	else
//		return (free(buff), NULL);
//	if (buff[len] == '\0')
//		return (free(buff), NULL);
//	next = ft_strchr_allocation(buff, len);
//	free (buff);
//	return (next);
//}

static void	clean_buff(char **buff)
{
	char	*next;
	size_t	len;
	char	*pos;

	pos = ft_strchr(*buff, SEPARATOR);
	if (pos)
		len = pos - *buff + 1;
	else
	{
		free(*buff);
		*buff = NULL;
		return ;
	}
	if ((*buff)[len] == '\0')
	{
		free(*buff);
		*buff = NULL;
		return ;
	}
	next = ft_strchr_allocation(*buff, len);
	free (*buff);
	*buff = next;
}

static char	*form_next_line(char *buff)
{
	size_t	len;
	char	*pos;

	pos = ft_strchr(buff, SEPARATOR);
	if (pos)
		len = pos - buff + 1;
	else
		len = ft_strlen(buff);
	return (ft_substr(buff, 0, len));
}

static char	*read_next_line(char *line, int fd)
{
	char	*buff;
	char	*tmp;
	int		read_bytes;

	read_bytes = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(line), line = NULL, NULL);
	buff[0] = '\0';
	while (read_bytes > 0 && !ft_strchr(line, SEPARATOR))
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			buff[read_bytes] = '\0';
			tmp = line;
			line = ft_strjoin(line, buff);
			free(tmp);
		}
	}
	free(buff);
	if (read_bytes < 0 || !line)
		return (free(line), line = NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!buff[fd] || !ft_strchr(buff[fd], SEPARATOR))
		buff[fd] = read_next_line(buff[fd], fd);
	if (!buff[fd])
		return (NULL);
	line = form_next_line(buff[fd]);
	if (!line || ft_strlen(line) == 0)
		return (free(buff[fd]), buff[fd] = NULL, free(line), NULL);
	clean_buff(&(buff[fd]));
	return (line);
}

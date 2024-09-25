/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:49 by bhajili           #+#    #+#             */
/*   Updated: 2024/09/25 04:11:19 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gnl_handler() returns:
//  1 - line with separator at the end or last line has been formed;
//  0 - line without separator has been formed;
// -1 - line has not been formed.
//
// formline() returns:
//  1 - line has been formed;
//  0 - line has not been formed;
//
// checkbuff() returns:
//  N - index of first non '\0' char in buff;
// -1 - buff is empty.

#include "get_next_line_bonus.h"

static void	cleanlbuff(char *buff, int len)
{
	int	i;

	i = -1;
	while (++i <= len)
		buff[i] = '\0';
}

static int	checkbuff(char *buff)
{
	int	i;

	i = -1;
	while (++i < BUFFER_SIZE)
		if (buff[i] != '\0')
			return (i);
	return (-1);
}

static int	formline(char **line, char *buff, int beg_i, int sep_i)
{
	char	*tmp_line;

	tmp_line = *line;
	*line = ft_strljoin(*line, &(buff[beg_i]), ft_strlen(*line), sep_i - beg_i);
	safefree(tmp_line);
	if (!(*line))
		return (0);
	return (1);
}

static int	gnl_handler(char **line, char *buff)
{
	int	begining_i;
	int	separator_i;
	int	result;

	result = 1;
	begining_i = checkbuff(buff);
	separator_i = ft_findlchar(buff, SEPARATOR, BUFFER_SIZE);
	if ((*line)[0] == '\0' && begining_i == -1)
		return (-1);
	if ((*line)[0] != '\0' && begining_i == -1)
		return (1);
	if (separator_i == -1)
	{
		separator_i = BUFFER_SIZE;
		result = 0;
	}
	if (formline(line, buff, begining_i, separator_i))
		cleanlbuff(buff, separator_i);
	else
		result = -1;
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	int			gnl_handler_result;
	char		*line;

	line = (char *)malloc(sizeof(char) * 1);
	if (fd > 2 && !buff[fd])
		buff[fd] = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!line || BUFFER_SIZE <= 0 || fd < 0 || !buff[fd] || read(fd, 0, 0) < 0)
		return (safefree(line));
	line[0] = '\0';
	while (1)
	{
		if (checkbuff(buff[fd]) == -1)
			if (read(fd, buff[fd], BUFFER_SIZE) < 0)
				return (safefree(line));
		gnl_handler_result = gnl_handler(&line, buff[fd]);
		if (gnl_handler_result == -1)
			return (safefree(line));
		if (gnl_handler_result == 1)
			return (line);
	}
}

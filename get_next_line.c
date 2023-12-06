/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byulbyul <byulbyul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:48:17 by byulbyul          #+#    #+#             */
/*   Updated: 2023/12/06 17:57:20 by byulbyul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gnl_handler() returns:
//  1 - line with separator has been formed;
//  0 - line without separator has been formed;
// -1 - line has not been formed.
//
// check_buff() returns:
//  N - index of first non '\0' char in buff;
// -1 - buff empty.

#include "get_next_line.h"

static char	*safe_free(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

static int	check_buff(char buff[BUFF_SIZE])
{
	int	i;

	i = -1;
	while (++i < BUFF_SIZE)
		if (buff[i] != '\0')
			return (i);
	return (-1);
}

static int	upd_prms(char **line, char buff[BUFF_SIZE], int beg_i, int sep_i)
{
	int		i;
	char	*tmp_line;

	i = -1;
	tmp_line = *line;
	*line = ft_strljoin(*line, &(buff[beg_i]), ft_strlen(*line), sep_i - beg_i);
	safe_free(tmp_line);
	if (!(*line))
		return (0);
	while (++i <= sep_i)
		buff[i] = '\0';
	return (1);
}

static int	gnl_handler(char **line, char buff[BUFF_SIZE])
{
	int	begining_i;
	int	separator_i;
	int	gnl_handler_result;

	gnl_handler_result = 1;
	begining_i = check_buff(buff);
	separator_i = ft_findcharl(buff, SEPARATOR, BUFF_SIZE);
	if ((*line)[0] == '\0' && begining_i == -1)
		return (-1);
	if ((*line)[0] != '\0' && begining_i == -1)
		return (1);
	if (separator_i == -1)
	{
		separator_i = BUFF_SIZE;
		gnl_handler_result = 0;
	}
	if (!upd_prms(line, buff, begining_i, separator_i))
		gnl_handler_result = -1;
	return (gnl_handler_result);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFF_SIZE];
	int			gnl_handler_result;
	char		*line;

	line = malloc(1);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (safe_free(line));
	line[0] = '\0';
	while (1)
	{
		if (check_buff(buff) == -1)
			if (read(fd, buff, BUFF_SIZE) < 0)
				return (safe_free(line));
		gnl_handler_result = gnl_handler(&line, buff);
		if (gnl_handler_result == -1)
			return (safe_free(line));
		if (gnl_handler_result == 1)
			return (line);
	}
}

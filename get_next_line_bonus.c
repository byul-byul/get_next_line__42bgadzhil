/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:49 by bhajili           #+#    #+#             */
/*   Updated: 2024/10/16 14:30:29 by bhajili          ###   ########.fr       */
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

static char	*get_sub_line(int fd,t_buff *buff)
{
	
}

// static char	*form_next_line(int fd, t_buff *buff)
// {
// 	char	*line;
// 	char	*tmp;
// 	int		readed;

// 	line = NULL;
// 	readed = BUFFER_SIZE;
// 	while (readed > 0)
// 	{
// 		if (NULL == buff->start)
// 		{
// 			readed = read(fd, buff->str, BUFFER_SIZE);
// 			if (readed < 0)
// 				return (safefree(buff->str));
// 			buff->start = buff->str;
// 		}
// 		sep_pos = ft_findlchar(SEPARATOR, buff->start, BUFFER_SIZE);
// 		tmp = line;
// 		line = ft_strjoin(line, get_sub_line(buff->start, sep_pos));
// 		safefree(tmp);
// 		if (NULL == line || sep_pos >= 0)
// 			return (line);
// 		cleanlbuff();
// 		if (sep_pos == -1 || sep_pos == BUFFER_SIZE)
// 			buff->start = NULL;
// 		else
// 			buff->start += sep_pos + 1;
// 	}
// }

int	ft_isinstr(int c, char *str)
{
	if (str)
		while (*str)
			if (c == *str++)
				return (1);
	return (0);
}

char	*ft_freeif(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

static char	*form_line_and_handle_buff(char *line, t_buff *buff, int flag)
{
	char	*tmp;

	tmp = line;
	line = ft_strjoin(line, buff->str);
	ft_freeif(tmp);
	if (flag == 1)
		handlebuff(buff, flag);
	else if (flag == 0)
		ft_freeif(buff->str);
	else if (flag == 2)
		handlebuff(buff, flag);
	return (line);
}

static char	*form_next_line(int fd, t_buff *buff)
{
	char	*line;
	int		readed;

	line = NULL;
	while (0 == ft_isinstr(SEPARATOR, buff->str))
	{
		line = form_line_and_handle_buff(line, buff, 1);
		if (NULL == line)
			return (ft_freeif(buff->str));
		readed = read(fd, buff->str, BUFFER_SIZE);
		if (readed < 0)
			if (!ft_freeif(line))
				return (ft_freeif(buff->str));
		if (readed < BUFFER_SIZE)
			return (form_line_and_handle_buff(line, buff, 0));
	}
	return (form_line_and_handle_buff(line, buff->str, 2));
}

char	*get_next_line(int fd)
{
	static t_buff	buff[MAX_FD];

	if (NULL == buff[fd].str)
	{
		buff[fd].str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		ft_bzero(buff[fd].str);
	}
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0 || NULL == buff[fd].str)
		return (safefree(buff[fd].str));
	return (form_next_line(fd, &(buff[fd])));
}

// static void	cleanlbuff(char *buff, int leln)
// {
// 	int	i;

// 	i = -1;
// 	while (++i <= len)
// 		buff[i] = '\0';
// }

// static int	checkbuff(char *buff)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < BUFFER_SIZE)
// 		if (buff[i] != '\0')
// 			return (i);
// 	return (-1);
// }

// static int	formline(char **line, char *buff, int beg_i, int sep_i)
// {
// 	char	*tmp_line;

// 	tmp_line = *line;
// 	*line = ft_strljoin(*line, &(buff[beg_i]), ft_strlen(*line), sep_i - beg_i);
// 	safefree2(tmp_line, buff);
// 	if (!(*line))
// 		return (0);
// 	return (1);
// }

// static int	gnl_handler(char **line, char *buff)
// {
// 	int	begining_i;
// 	int	separator_i;
// 	int	result;

// 	result = 1;
// 	begining_i = checkbuff(buff);
// 	separator_i = ft_findlchar(buff, SEPARATOR, BUFFER_SIZE);
// 	if ((*line)[0] == '\0' && begining_i == -1)
// 		return (-1);
// 	if ((*line)[0] != '\0' && begining_i == -1)
// 		return (1);
// 	if (separator_i == -1)
// 	{
// 		separator_i = BUFFER_SIZE;
// 		result = 0;
// 	}
// 	if (formline(line, buff, begining_i, separator_i))
// 		cleanlbuff(buff, separator_i);
// 	else
// 		result = -1;
// 	return (result);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buff[MAX_FD];
// 	int			gnl_handler_result;
// 	char		*line;

// 	if (fd > 2 && !(buff[fd]))
// 		buff[fd] = (char *)malloc(sizeof(char) * BUFFER_SIZE);
// 	line = (char *)malloc(sizeof(char) * 1);
// 	if (!line || BUFFER_SIZE <= 0 || fd < 0 || !buff[fd] || read(fd, 0, 0) < 0)
// 		return (safefree2(line, buff[fd]));
// 	line[0] = '\0';
// 	while (1)
// 	{
// 		if (checkbuff(buff[fd]) == -1)
// 			if (read(fd, buff[fd], BUFFER_SIZE) < 0)
// 				return (safefree2(line, buff[fd]));
// 		gnl_handler_result = gnl_handler(&line, buff[fd]);
// 		if (gnl_handler_result == -1)
// 			return (safefree2(line, buff[fd]));
// 		if (gnl_handler_result == 1)
// 			return (line);
// 	}
// }

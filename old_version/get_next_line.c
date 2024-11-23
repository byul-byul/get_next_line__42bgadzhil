/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:49 by bhajili           #+#    #+#             */
/*   Updated: 2024/10/22 08:41:05 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	buffhandler(t_buff *buff, int sep_index)
{
	int		i;

	i = -1;
	if (sep_index == -1)
	{
		while (++i < BUFFER_SIZE)
			buff->ptr[i] = '\0';
		buff->val = buff->ptr;
	}
	else
	{
		while (++i <= sep_index)
			buff->val[i] = '\0';
		if (&(buff->val[i]) - buff->ptr == BUFFER_SIZE)
			buff->val = buff->ptr;
		else
			buff->val = &(buff->val[i]);
	}
}

static char	*form_line_and_handle_buff(char *line, t_buff *buff, int sep_index)
{
	char	*tmp;
	size_t	buff_len;

	tmp = line;
	buff_len = sep_index;
	if (sep_index == -1)
		buff_len = ft_strlen(buff->val);
	line = ft_strljoin(line, buff->val, ft_strlen(line), buff_len);
	ft_freeif(&tmp);
	buffhandler(buff, sep_index);
	return (line);
}

static char	*form_next_line(int fd, t_buff *buff)
{
	char	*line;
	int		readed;
	int		sep_index;

	line = NULL;
	while (1)
	{
		if (ft_strlen(buff->val) == 0)
		{
			readed = read(fd, buff->ptr, BUFFER_SIZE);
			if (readed <= 0)
			{
				ft_freeif(&buff->ptr);
				if (readed < 0)
					return (ft_freeif(&line));
				return (line);
			}
		}
		else
		{
			sep_index = ft_charindex(SEPARATOR, buff->val);
			line = form_line_and_handle_buff(line, buff, sep_index);
			if (sep_index == -1)
				continue ;
			else
			{
				if (ft_strlen(buff->val) == 0)
					ft_freeif(&buff->ptr);
				return (line);
			}
		}
	}
}

char	*get_next_line(int fd)
{
	static t_buff	buff[TOTAL_FD_COUNT];

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (NULL == buff[fd].ptr)
	{
		buff[fd].ptr = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (NULL == buff[fd].ptr)
			return (NULL);
		buff[fd].ptr[BUFFER_SIZE] = '\0';
		buffhandler(&(buff[fd]), -1);
	}
	return (form_next_line(fd, &(buff[fd])));
}

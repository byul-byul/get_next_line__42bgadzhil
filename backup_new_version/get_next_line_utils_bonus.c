/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:58 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/18 11:03:45 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)malloc(sizeof(*s) * (len + 1));
	if (!(sub) || !s)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sub[j] = s[i];
			j++;
		}
		i++;
	}
	sub[j] = 0;
	return (sub);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	int		size1;
	int		size2;
	int		i;
	int		j;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < size1)
		res[i++] = s1[j++];
	j = 0;
	while (j < size2)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

//char	*ft_strjoin(char *line, char *buffer)
//{
//	char	*line2;
//	int		i;
//	int		j;

//	i = 0;
//	j = 0;
//	if (!line)
//	{
//		line = malloc(1);
//		if (!line)
//			return (NULL);
//		line [0] = '\0';
//	}
//	line2 = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
//	if (!line2)
//		return (free(line), NULL);
//	while (line[i])
//	{
//		line2[i] = line[i];
//		i++;
//	}
//	while (buffer[j])
//		line2[i++] = buffer[j++];
//	free(line);
//	return (line2[i] = '\0', line2);
//}

char	*ft_strchr(char *line, int c)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == (char)c)
			return (&line[i]);
		i++;
	}
	return (NULL);
}

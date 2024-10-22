/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:58 by bhajili           #+#    #+#             */
/*   Updated: 2024/10/22 08:47:15 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_charindex(int c, char *str)
{
	int	i;

	i = -1;
	if (str)
		while (str[++i])
			if (str[i] == c)
				return (i);
	return (-1);
}

char	*ft_freeif(char **str)
{
	if (str)
	{
		if (*str)
			free(*str);
		*str = NULL;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s)
		while (s[len])
			len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	const char	*src_ptr;
	char		*dst_ptr;

	if (dst == src)
		return (dst);
	src_ptr = src;
	dst_ptr = dst;
	while (len--)
		*dst_ptr++ = *src_ptr++;
	return (dst);
}

char	*ft_strljoin(char const *s1, char const *s2, size_t len1, size_t len2)
{
	char	*result;

	if (NULL == s1 && NULL == s2)
		return (NULL);
	if (NULL == s1)
	{
		result = malloc(len2 + 1);
		if (result)
		{
			ft_memcpy(result, s2, len2 + 1);
			result[len2 + 1] = '\0';
		}
	}
	else if (NULL == s2)
	{
		result = malloc(len1 + 1);
		if (result)
		{
			ft_memcpy(result, s1, len1 + 1);
			result[len1 + 1] = '\0';
		}
	}
	else
	{
		result = malloc(len1 + len2 + 1);
		if (result)
		{
			ft_memcpy(result, s1, len1);
			ft_memcpy(result + len1, s2, len2 + 1);
			result[len1 + len2 + 1] = '\0';
		}
	}
	return (result);
}

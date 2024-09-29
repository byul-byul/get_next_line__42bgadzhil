/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:58 by bhajili           #+#    #+#             */
/*   Updated: 2024/09/28 18:44:11 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*src_ptr;
	char		*dest_ptr;

	if (dest == src)
		return (dest);
	src_ptr = src;
	dest_ptr = dest;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}

char	*ft_strljoin(char const *s1, char const *s2, size_t s1_l, size_t s2_l)
{
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (s1_l + s2_l + 2));
	if (result)
	{
		ft_memcpy(result, s1, s1_l);
		ft_memcpy(result + s1_l, s2, s2_l + 1);
		result[s1_l + s2_l + 1] = '\0';
	}
	return (result);
}

size_t	ft_findlchar(const char *str, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		if (str[i] == (char)c)
			return (i);
	return (-1);
}

char	*safefree(char *str, char *buff)
{
	if (str)
		free(str);
	if (buff)
		free(buff);
	return (NULL);
}

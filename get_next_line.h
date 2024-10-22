/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:38 by bhajili           #+#    #+#             */
/*   Updated: 2024/10/21 16:33:45 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // DELETE

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# define SEPARATOR		'\n'
# define TOTAL_FD_COUNT	1

typedef struct s_buff
{
	char	*val;
	char	*ptr;
}				t_buff;

char	*get_next_line(int fd);
char	*ft_strljoin(char const *s1, char const *s2, size_t len1, size_t len2);
void	*ft_memcpy(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_freeif(char **str);
int		ft_charindex(int c, char *str);

#endif
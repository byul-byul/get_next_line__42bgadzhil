/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:38 by bhajili           #+#    #+#             */
/*   Updated: 2024/10/11 21:43:28 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

# define SEPARATOR		'\n'
# define MAX_FD			4096

typedef struct s_buff
{
	char	*str;
	char	*start;
}				t_buff;

char	*get_next_line(int fd);
char	*ft_strljoin(char const *s1, char const *s2, size_t s1_l, size_t s2_l);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_findlchar(const char *str, int c, size_t len);
char	*safefree2(char *str, char *buff);

#endif
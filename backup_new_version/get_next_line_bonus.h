/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:38 by bhajili           #+#    #+#             */
/*   Updated: 2024/12/18 11:03:59 by bhajili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 4096
# endif

# ifndef MAX_FD
#  define MAX_FD OPEN_MAX
# endif

# define SEPARATOR '\n'

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
//char	*ft_strchr_allocation(char *line, int len);
//char	*ft_strchar_rev(char *line, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
//char	*ft_strjoin(char *line, char *buffer);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(char *line, int c);

#endif
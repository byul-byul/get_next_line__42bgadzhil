/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhajili <bhajili@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 23:09:38 by bhajili           #+#    #+#             */
/*   Updated: 2024/11/23 21:43:57 by bhajili          ###   ########.fr       */
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

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strchr_allocation(char *line, int len);
char	*ft_strchar_rev(char *line, int c);
char	*ft_strjoin(char *line, char *buffer);
char	*ft_strchr(char *line, int c);
char	*ready_for_next(char *line);
char	*read_line(char *line, int fd);
char	*clean_line(char *line);
char	*ready_for_next(char *line);

#endif
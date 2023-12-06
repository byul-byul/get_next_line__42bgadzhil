/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byulbyul <byulbyul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:59:32 by byulbyul          #+#    #+#             */
/*   Updated: 2023/12/06 17:57:57 by byulbyul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE	20
# define SEPARATOR	'\n'

char	*get_next_line(int fd);
char	*ft_strljoin(char const *s1, char const *s2, size_t s1_l, size_t s2_l);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_findcharl(const char *str, int c, size_t len);

#endif
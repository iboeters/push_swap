/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 12:53:04 by iboeters      #+#    #+#                 */
/*   Updated: 2022/01/26 11:47:34 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 32

size_t	ft_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
int		gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_substr(char *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif

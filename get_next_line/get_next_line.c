/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: iboeters <iboeters@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 16:17:46 by iboeters      #+#    #+#                 */
/*   Updated: 2021/05/03 14:38:47 by iboeters      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_fd(char **buf, int fd)
{
	int ret;

	*buf = gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!*buf)
		return (-1);
	ret = read(fd, *buf, BUFFER_SIZE);
	return (ret);
}

static int		return_value(int ret, int malloc_check, char **buf)
{
	if (ret == -1 || malloc_check == -1)
	{
		if (*buf)
		{
			free(*buf);
			*buf = NULL;
		}
		return (-1);
	}
	else if (ret == 0)
	{
		if (*buf)
		{
			free(*buf);
			*buf = NULL;
		}
		return (0);
	}
	else
		return (1);
}

static int		join(char **line, char **buf)
{
	*line = gnl_strjoin(*line, *buf);
	if (*buf)
		free(*buf);
	*buf = NULL;
	if (!*line)
		return (-1);
	return (0);
}

static int		join_and_save(char **line, char **buf)
{
	int		i;
	char	*tmp;
	char	*end;

	i = 0;
	while ((*buf)[i] != '\n')
		i++;
	end = gnl_substr(*buf, 0, i);
	if (!end)
		return (-1);
	*line = gnl_strjoin(*line, end);
	free(end);
	tmp = gnl_substr(*buf, i + 1, gnl_strlen(*buf) - i);
	if (!tmp || !*line)
		return (-1);
	if (*buf)
		free(*buf);
	*buf = tmp;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char				*buf[OPEN_MAX];
	int						ret;
	int						malloc_check;

	ret = 1;
	malloc_check = 0;
	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	*line = gnl_calloc(1, sizeof(char));
	while (ret > 0 && *line)
	{
		if (buf[fd] == NULL)
			ret = read_fd(&buf[fd], fd);
		if (buf[fd] && !gnl_strchr(buf[fd], '\n') && ret > 0)
			malloc_check = join(line, &buf[fd]);
		else if (buf[fd] && gnl_strchr(buf[fd], '\n') && ret > 0)
		{
			malloc_check = join_and_save(line, &buf[fd]);
			return (return_value(ret, malloc_check, &buf[fd]));
		}
		if (malloc_check == -1 || ret <= 0)
			return (return_value(ret, malloc_check, &buf[fd]));
	}
	return (return_value(ret, -1, &buf[fd]));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:43:51 by bastalze          #+#    #+#             */
/*   Updated: 2025/12/10 13:51:09 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*make_remainder(char *remainder, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (line[i] != '\n')
		i++;
	i++;
	j = 0;
	while (line[i + j] != 0)
	{
		remainder[j] = line[i + j];
		j++;
	}
	remainder[j] = 0;
	line[i] = 0;
	return (line);
}

char	*add_remainder(char *remainder)
{
	char	*rline;
	size_t	i;
	
	if (!remainder)
		return (NULL);
	rline = malloc(BUFFER_SIZE + 1);
	if (rline == NULL)
		return (NULL);
	i = 0;
	while (remainder[i] != 0)
	{
		rline[i] = remainder[i];
		i++;
	}
	rline[i] = 0;
	ft_bzero(remainder);
	return (rline);
}
/*
char	*finding_nl(char *remainder, char *buffer, int fd)
{
	char	*line1;
	int		i;

	line1 = add_remainder(remainder);
	i = 1;
	while (i >= 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		buffer[i] = 0;
		line1 = ft_strjoin(line1, buffer);
		if ((i < BUFFER_SIZE && ft_str_i(buffer, '\n') == 0) || (i == 0))
			return (line1);
		else if (ft_str_i(buffer, '\n') != 0)
			return (make_remainder(remainder, line1));
	}
	return (NULL);
}
*/

char	*finding_nl(char *remainder, char *buffer, int fd)
{
	int	b_read;
	char	*line;

	line = add_remainder(remainder);
	while ((b_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (b_read < 0)
			return (NULL);
		buffer[b_read] = 0;
		line = ft_strjoin(line, buffer);
		if (ft_str_i(buffer, '\n') != 0)
			return (make_remainder(remainder, line));
		else if (b_read < BUFFER_SIZE)
			return (line);
	}
	if (ft_strlen(line) == 0)
		return (NULL);
	return (line);
}

char	*nl_in_remainder(char *remainder)
{
	char	*line;
	size_t	i;
	size_t	j;

	line = malloc(BUFFER_SIZE + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\n';
	i++;
	line[i] = 0;
	j = 0;
	while (remainder[i + j] != 0)
	{
		remainder[j] = remainder[i + j];
		j++;
	}
	remainder[j] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		buffer[BUFFER_SIZE + 1];

	ft_bzero(buffer);
	if (ft_str_i(remainder, '\n') != 0)
		return (nl_in_remainder(remainder));
	else
		return (finding_nl(remainder, buffer, fd));
}
/*
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *result;

	fd = open("testfile_hello.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	while ((result = get_next_line(fd)))
	{
		printf("%s\n", result);
		free(result);
	}
	close(fd);
	return 0;
}
*/

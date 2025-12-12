/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:43:51 by bastalze          #+#    #+#             */
/*   Updated: 2025/12/12 13:06:35 by bastalze         ###   ########.fr       */
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
	char	*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = 0;
	line = ft_strjoin(line, remainder);
	remainder[0] = 0;
	return (line);
}

char	*find_nl(char *remainder, char *buffer, int fd)
{
	int		b_read;
	char	*line;

	line = add_remainder(remainder);
	if (!line)
		return (NULL);
	while (1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read < 0)
			return (free(line), NULL);
		else if (b_read == 0)
		{
			if (ft_strlen(line) != 0)
				return (line);
			else 
				return (free(line), NULL);
		}
		buffer[b_read] = 0;
		line = ft_strjoin(line, buffer);
		if (!line)
			return (NULL);
		if (ft_str_i(buffer, '\n') != 0)
			return (make_remainder(remainder, line));
		else if (b_read < BUFFER_SIZE)
			return (line);
	}
}

char	*nl_in_remainder(char *remainder)
{
	char	*line;
	size_t	i;
	size_t	j;

	line = malloc(BUFFER_SIZE + 1);
	if (!line)
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

	buffer[0] = 0;
	if (ft_str_i(remainder, '\n') != 0)
		return (nl_in_remainder(remainder));
	else
		return (find_nl(remainder, buffer, fd));
}

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *result;
	int i = 0;

	fd = open("olnonl.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	result = get_next_line(fd);
	while (i < 10)
	{
		printf("%s\n", result);
		free(result);
		i++;
	}
	close(fd);
	return 0;
}


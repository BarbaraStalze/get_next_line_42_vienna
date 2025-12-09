/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:43:51 by bastalze          #+#    #+#             */
/*   Updated: 2025/12/09 17:31:11 by bastalze         ###   ########.fr       */
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

	rline = malloc(BUFFER_SIZE + 1);
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

char	*finding_nl(char *remainder, char *buffer, int fd)
{
	char	*line1;
	char	*line2;
	int		i;

	line1 = add_remainder(remainder);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		buffer[i] = 0;
		line2 = ft_strjoin(line1, buffer);
		line1 = line2;
		if ((i < BUFFER_SIZE && ft_str_i(buffer, '\n') == 0) || (i == 0))
			return (line1);
		else if (ft_str_i(buffer, '\n') != 0)
			return (make_remainder(remainder, line1));
	}
	return (NULL);
}

char	*nl_in_remainder(char *remainder)
{
	char	*line;
	size_t	i;
	size_t	j;

	line = malloc(BUFFER_SIZE + 1);
	i = 0;
	while (remainder[i] != '\n')
	{
		line[i] = remainder[i];
		i++;
	}
	line[i] = '\n';
	line[i++] = 0;
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

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	char *result;

	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
		return 1;
	while ((result = get_next_line(fd)))
	{
		printf("%s\n", result);
		free(result);
	}
	printf("%s\n", result);
	free(result);
	printf("%s\n", result);
	free(result);
	close(fd);
	return 0;
}

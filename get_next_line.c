/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:43:51 by bastalze          #+#    #+#             */
/*   Updated: 2025/12/03 17:08:39 by bastalze         ###   ########.fr       */
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
	line[i] = '\n';
	i++;
	j = 0;
	while (line[i + j])
	{
		remainder[j] = line[i + j];
		j++;
	}
	remainder[j] = 0;
	line[i] = 0;
	return (line);
}

char	*finding_nl(static char *remainder, char *buffer, int fd)
{
	char	*line1;
	char	*line2;
	int		i;
		
	line1 = malloc(BUFFER_SIZE + 1);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buffer[i] = 0;
		line2 = strjoin(line1, buffer);
		free(line1);
		line1 = line2;
		if (i < BUFFER_SIZE)
			return (line1);
		if else (ft_str_i(buffer, '\n') != 0)
			return (make_remainder(remainder, buffer, line1));
	}
	if (i == 0)
		return (line1);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];
	char		line[BUFFER_SIZE + 1];
	char		*rline;

	bzero(line);
	if (ft_str_i(remainder, '\n') != 0)
		return (make_remainder(remainder, line));
	line = finding_nl(remainder, line, fd);
	if (line == NULL)
		return (NULL);
	if (remainder[0] != 0)
	{
		rline = ft_strjoin(remainder, line);
		bzero(remainder);
		free(line);
		return (rline);
	}
	else
		return (line);
}

#include <stdio.h>
int main(void)
{
	char *result;

	result = get_next_line(0);
	printf("%s\n", result);
	while (result != NULL)
	{
		result = get_next_line(0);
		printf("%s\n", result);
	}
}

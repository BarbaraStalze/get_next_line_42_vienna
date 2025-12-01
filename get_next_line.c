/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:43:51 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/25 17:27:13 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*make_remainder(static char *remainder, char *buffer, char *line)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (buffer != '\n')
	{
		line [(strlen(line)) + i] = buffer[i];
		i++;
	}
	line[(strlen(line)) + i] = '\n';
	i++;
	j = 0;
	while (rest[i])
	{
		remainder[j] = buffer[i + j];
		j++;
	}
	remainder[j] = 0;
	return (line);
}

char	*finding_nl(static char * remainder, char *buffer, size_t i, int fd)
{
	char	*line;
	size_t	multi;

	multi = 1;
	if (!(ft_str_i(buffer, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buffer[i] = 0;
		line = malloc((BUFFER_SIZE * multi) + 1);
		// memcpy(line, buffer);
		// line[(BUFFER_SIZE * multi) + 1] = 0;
		if (i < BUFFER_SIZE)
			return (line);
		multi++;
		finding_nl(buffer, i, fd);
		
	}
	else if (ft_str_i(buffer, '\n'))
	{
		line = make_remainder(remainder, buffer, line);
	}
	return (line);
}

char	*first_buffer(static char *remainder, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	size_t	i;

	i = 0;
	i = read(fd, buffer, BUFFER_SIZE);
	if (i == -1)
		return (NULL);
	buffer[i] = 0;
	if (i > BUFFER_SIZE)
		return (buffer);
	return (finding_nl(remainder, buffer, i, fd));
}

char	*cc_remainder(static char *remainder, int fd)
{
	char *line;
	char *result;
	char line[BUFFER_SIZE + 1];

	if (ft_str_i(remainder, '\n'))
		//bzero(line);
		return (make_remainder(remainder, remainder, line);
	line = first_buffer(remainder, fd);
	if (line == NULL)
		return (NULL);
	result = ft_strjoin(remainder, line);
	//remainder = 0 //bzero(remainder);
	free(line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];

	if (!remainder)
		return (finding_nl(fd));
	else
		return (cc_remainder(remainder, fd));
}

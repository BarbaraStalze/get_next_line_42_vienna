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

char	*make_remainder(static char *remainder, int fd)
{
	
}

char	*finding_nl(char *buffer, size_t i, int fd)
{
	char	*line;
	size_t	multi;

	multi = 2;
	while (!(ft_str_i(buffer, '\n')))
	{
		i = 0;
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		buffer[i] = 0;
		if (i > BUFFER_SIZE)
			return (buffer);
		line = malloc((BUFFER_SIZE * multi) + 1);
		
		multi++;
	}
}

char	*first_buffer(int fd)
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
	if (!(ft_str_i(buffer, '\n')
		finding_nl(buffer, i, fd);
	if ((ft_str_i(buffer, '\n')))
		make_remainder(ft_str_i(buffer, '\n'), fd);
}

char	*cc_remainder(static char *remainder, int fd)
{
	char *line;
	char *result;

	line = first_buffer(fd);
	if (line == NULL)
		return (NULL);
	result = ft_strjoin(remainder, line);
	free(line);
	return result;
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE + 1];

	if (!remainder)
		return (finding_nl(fd));
	else
		return (cc_remainder(remainder, fd));
}

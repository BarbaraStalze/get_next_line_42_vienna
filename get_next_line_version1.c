/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_version1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 15:28:40 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/21 15:35:12 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t bytes_read;
	char *buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = 0;

	char *storage1;
	int i1;
	static char *remainder;
	int r;

	i = 0;
	r = 0;
	while (buffer[bytes_read] != \n && buffer)
	{
		storage1[i1] = buffer[bytes_read];
		if (buffer[bytes_read] == \n)
			break;
		i1++;
		bytes_read++;
	}
	storage1[i1] = 0;
	if (buffer[bytes_read] == \n)
	{
		bytes_read++;
		while (buffer)
		{
			remainder[r] = buffer[bytes_read];
			bytes_read++;
			r++;
		}
		remainder[r] = 0;
	}
}

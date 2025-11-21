/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:43:51 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/21 18:33:59 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*finding_nl(fd)
{
	
}

char	*cc_remainder(static char *remainder, int fd)
{
	char *line;
	char *result;

	line = finding_nl(fd);
	result = ft_strjoin(remainder, line);
	free(line);
	return result;
}

char	*get_next_line(int fd)
{
	static char	remainder[BUFFER_SIZE];

	if (!remainder)
		return (finding_nl(fd));
	else
		return (cc_remainder(remainder, fd));
}

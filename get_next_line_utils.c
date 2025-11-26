/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:44:17 by bastalze          #+#    #+#             */
/*   Updated: 2025/11/25 12:57:57 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_string(char *string, char const *s1, int s1len)
{
	int	i;

	i = 0;
	while (s1len > 0)
	{
		string[i] = s1[i];
		i++;
		s1len--;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	char	*string;
	int		i;
	int		j;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	string = malloc(s1len + s2len + 1);
	if (!string)
		return (0);
	i = ft_string(string, s1, s1len);
	j = 0;
	while (s2len > 0)
	{
		string[i] = s2[j];
		i++;
		j++;
		s2len--;
	}
	string[i] = 0;
	return (string);
}

int	ft_str_i(const char *s, int c)
{
	unsigned char	find;
	size_t			strlen;

	strlen = ft_strlen(s);
	find = (unsigned char) c;
	while (strlen + 1 > 0)
	{
		if (*s == find)
			return (strlen);
		s++;
		strlen--;
	}
	return (0);
}

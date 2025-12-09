/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bastalze <bastalze@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:44:43 by bastalze          #+#    #+#             */
/*   Updated: 2025/12/09 12:02:30 by bastalze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#include <stdlib.h>
#include <unistd.h>

char    *get_next_line(int fd);
void    ft_bzero(char *s);
size_t  ft_strlen(const char *s);
char    *ft_strjoin(char *s1, char const *s2);
int		ft_str_i(const char *s, int c);

#endif

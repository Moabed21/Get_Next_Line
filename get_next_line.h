/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:01:03 by moabed            #+#    #+#             */
/*   Updated: 2025/09/09 04:22:39 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1024
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char		*get_next_line(int fd);
char		*ft_strdup(char *src, int bytes);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);

static char	*readappend(int fd, char leftovers);
static char	*prepare_next_leftovers(char *leftovers);
char		*extract_line(char *leftovers);

#endif
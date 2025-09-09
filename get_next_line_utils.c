/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:00:57 by moabed            #+#    #+#             */
/*   Updated: 2025/09/09 04:41:20 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*totalsize;
	char	*ptr;

	totalsize = malloc((ft_strlen(s2) + ft_strlen(s1) + 1) * sizeof(char));
	ptr = totalsize;
	if (totalsize == NULL)
		return (NULL);
	while (*s1)
	{
		*totalsize++ = *s1++;
	}
	while (*s2)
	{
		*totalsize++ = *s2++;
	}
	*totalsize = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	x;

	x = (char)c;
	while (*s)
	{
		if (*s == x)
			return ((char *)s);
		s++;
	}
	if (x == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(char *src, int bytes)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * bytes + 1);
	if (!(dest))
		return (NULL);
	while (i < bytes)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

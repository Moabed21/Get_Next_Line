/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:01:00 by moabed            #+#    #+#             */
/*   Updated: 2025/09/09 04:51:55 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *leftovers)
{
	int		i;
	int		j;
	char	*p;

	j = 0;
	i = 0;
	while (leftovers[i] != '\n' && leftovers[i])
		i++;
	if (leftovers[i] == '\n')
    {
        p = malloc(sizeof(char) * (i + 2));
    }
    else
        p = malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	while (j < i)
	{
		p[j] = leftovers[j];
		j++;
	}
	p[j++] = '\n';
	p[j] = '\0';
	return (p);
}

static char	*readappend(int fd, char *leftovers)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	while (!ft_strchr(leftovers, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		leftovers = ft_strjoin(leftovers, buffer);
	}
	return (leftovers);
}

static char	*prepare_next_leftovers(char *leftovers)
{
	int		i;
	int	j;
	char	*nlo;

	j = 0;
	i = 0;
	while (leftovers[i] != '\n' && leftovers[i])
		i++;
	if (!leftovers[i])
	{
		free(leftovers);
		return (NULL);
	}
	i++;
	nlo = malloc(sizeof(char) * (ft_strlen(leftovers) - i + 1));
	if (!nlo)
		return (NULL);
	    while (leftovers[i])
		nlo[j++] = leftovers[i++];
    	nlo[j] = '\0';
    	free(leftovers);
    	return (nlo);
}

char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		*line;

	leftovers = readappend(fd, leftovers);
	if (!leftovers)
		return (NULL);
	line = extract_line(leftovers);
	leftovers = prepare_next_leftovers(leftovers);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int	fd;

// 	char	p[101];
// 	int	bytes;
// 	int	i;
// 	static char *leftover;
// 	i = 0;
// fd = open(argv[1], O_RDONLY);
// 	bytes = read(fd ,p,100);
// 	while (i < bytes )
// 	{
// 		write (1, &p[i], 1);
// 		i++;
// 		if (p[i] == '\n')
// 		{
// 			write (1, &p[i], 1);
// 			i++;
// 			leftover =ft_strdup(&p[i],bytes - i);
// 			break ;
// 		}
// 	}
// 	while (*leftover)
// 	{
// 		write(1,leftover,1);
// 		leftover++;
// 	}
// printf("%s", get_next_line(fd));
//}

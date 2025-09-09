/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:01:00 by moabed            #+#    #+#             */
/*   Updated: 2025/09/09 03:47:57 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *extract_line(char *leftovers)
{
	int	i;
	char	*p;
	i = 0;
	while(leftovers[i] != '\n')
	{
		i++;
	}
	p = malloc(sizeof(char) *);
}
char	*get_next_line(int fd)
{
	static char	*leftovers;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes;
	int			i;

	i = 0;
	while (!ft_strchr(leftovers, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		leftovers = ft_strjoin(leftovers, buffer);
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	// 	char	p[101];
	// 	int	bytes;
	// 	int	i;
	// 	static char *leftover;
	// 	i = 0;
	//fd = open(argv[1], O_RDONLY);
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
	//printf("%s", get_next_line(fd));
}

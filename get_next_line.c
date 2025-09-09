/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:01:00 by moabed            #+#    #+#             */
/*   Updated: 2025/09/10 00:20:37 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *leftovers)
{
	int	len;

	len = 0;
	if ( !leftovers[len])
		return (NULL);
		
	while (leftovers[len] && leftovers[len] != '\n')
	{
		len++;
	}
	if(leftovers[len] =='\n')
		len++;
	return (ft_strdup(leftovers,len));
}

static char	*readappend(int fd, char *leftovers)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp_ptr;
	int		bytes;

	while (!ft_strchr(leftovers, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buffer[bytes] = '\0';
		temp_ptr = leftovers;
   		leftovers = ft_strjoin(temp_ptr, buffer); 
  		free(temp_ptr);
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
	if (!leftovers || !*leftovers)
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

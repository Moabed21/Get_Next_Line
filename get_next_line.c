/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabed <moabed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 12:01:00 by moabed            #+#    #+#             */
/*   Updated: 2025/09/04 13:48:02 by moabed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void 	get_next_line(int fd)
{
	char buf[BUFFER_SIZE];
	size_t readbuf;
	static int	i;

	i = 0;
	readbuf = read(fd,buf,BUFFER_SIZE-1);
	// if (fd = -1 || readbuf == 0)
	// 	return (NULL);
	while(buf[i]  )
	{
		write(fd,&buf[i],1);
		i++;
	}

	// 1)our get_next_line() function should letyou read the
	// text file pointed to by the file descriptor, one line at a time.
}
#include <stdio.h>
int	main(int argc , char **argv)
{
int fd = open(argv[1], O_RDONLY); //system by default
//assign it to number3
	char buffer[BUFFER_SIZE];
	size_t file = read(3, buffer, BUFFER_SIZE-1);
	//printf("%s", buffer);
	get_next_line(file);
	
}
// 2) Your function should return the line that was read.
// If there is nothing left to read or if an error occurs,it should return NULL.

// 3)Please note that the returned line should include the terminating \n character,
// except when the end of the file is reached and the file does not end with a \n
// character

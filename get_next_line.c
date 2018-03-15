/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kprytkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 21:04:18 by kprytkov          #+#    #+#             */
/*   Updated: 2018/03/12 21:04:20 by kprytkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

// int		i_am_for_reading(int fd, char *buffer)
char		*i_am_for_reading(int fd)
{
	int		read_bytes;
	char	*buffer;
	

	if (!(buffer = malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	// while ((read_bytes = read(fd, buffer, BUFF_SIZE)) > 0)
	// {
	// 	buffer[read_bytes] = '|';
	// 	ft_putstr(buffer);
	// }
	// ft_putchar('\n');
	read_bytes = read(fd, buffer, BUFF_SIZE);
	buffer[read_bytes] = '\0';
	return(buffer);
	
}

int get_next_line(const int fd, char **line)
{
	char	*result_string;

	printf("The value of FD: %i\n", fd );
	printf("BUFF_SIZE = %i\n", BUFF_SIZE );
	if (fd == -1)
		return (0);
	result_string = i_am_for_reading(fd);
	printf("%s\n", result_string );

	

	return (0);
}
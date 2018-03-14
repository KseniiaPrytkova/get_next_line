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
char	i_am_for_reading(int fd)
{
	int		ret;
	char	*buffer;
	int		counter;

	counter = 0;

	if (!(buffer = malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (0);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		counter++;
		printf("%i\n", counter);	}
	// ret = read(fd, buffer, BUFF_SIZE);
	buffer[ret] = '\0';

	return(*buffer);
}

int get_next_line(const int fd, char **line)
{
	char	*result_string;
	int		ret;
	printf("The value of FD: %i\n", fd );
	printf("BUFF_SIZE = %i\n", BUFF_SIZE );
	
	*result_string = i_am_for_reading(fd);
	ft_putstr(result_string);
	return (0);
}
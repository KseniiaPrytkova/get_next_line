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
char		*i_am_for_reading(int fd, char *result_string)
{
	int		read_bytes;
	char	*buffer_for_read;
	char	*buffer_for_join[BUFF_SIZE + 1];
	static int		is_it_first_time;
	int 	counter;
	
	is_it_first_time = 0;
	counter = 0;
	if (!(buffer_for_read = malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);

	while ((read_bytes = read(fd, buffer_for_read, BUFF_SIZE)) > 0)
	{
		buffer_for_read[read_bytes] = '|';
		printf("I'M BUFFER: %s\n", buffer_for_read);
		// ft_putstr(buffer);
		if (is_it_first_time == 0)
		{
			printf("---->>>I'M IN THE 1ST TIME --->>>\n");
			ft_bzero(result_string, BUFF_SIZE + 1);
			ft_memccpy(result_string, buffer_for_read, '|', BUFF_SIZE);
			printf("%s\n", result_string );
			is_it_first_time = 1;
			printf("CATCH U!!!\n" );

		}
		if (is_it_first_time >  1)
		{
			printf("--->>>>i'm in join!!!\n");
			printf("ITERATION #:%i\n", counter );
			ft_bzero(buffer_for_join, BUFF_SIZE + 1);
			ft_memccpy(buffer_for_join, buffer_for_read, '|', BUFF_SIZE);

			printf("BUFFER_FOR_JOIN: %s\n", buffer_for_join );

			printf("result_string HERE:%s\n", result_string );

			result_string = ft_strjoin(result_string, buffer_for_join);

			printf("AFTER_CONCATENATION: %s\n", result_string );
			is_it_first_time = 2;
			printf("\n" );
		}

	is_it_first_time ++;
	counter++;
		// ft_bzero(result_string, BUFF_SIZE + 1);
		// ft_memccpy(result_string, buffer, '|', BUFF_SIZE );
		// printf("%s", result_string );
		
	}

	// read_bytes = read(fd, buffer, BUFF_SIZE);
	// buffer[read_bytes] = '\0';
	// 	ft_putstr(buffer);
	// 	ft_putchar('\n');
	// ft_bzero(result_string, BUFF_SIZE + 4);
	// ft_memccpy(result_string, buffer, '\0', BUFF_SIZE );

	return(result_string);
	
}

int get_next_line(const int fd, char **line)
{
	char	*result_string;

	printf("The value of FD: %i\n", fd );
	printf("BUFF_SIZE = %i\n", BUFF_SIZE );
	if (fd == -1)
		return (0);

	result_string = i_am_for_reading(fd, result_string);
	printf("\n");

	printf("I AM HERE --->>>\n");
	printf("%s\n", result_string );

	

	return (0);
}
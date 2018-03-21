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

char	*join_me(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result_string;

	s1_len = 0;
	s2_len = 0;
	result_string = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		result_string = ft_strnew(s1_len + s2_len + 1);
		if (result_string)
		{
			ft_strncpy(result_string, s1, s1_len);
			free(s1);
			ft_strncpy((result_string + s1_len), s2, s2_len);
		}
		else
			return (NULL);
	}
	return (result_string);
}

char		*i_am_for_reading(int fd, char *result_string)
{
	int				read_bytes;
	char			buffer_for_read[BUFF_SIZE + 1];
	int 			counter;
	size_t			res_str_len;

	res_str_len = 0;
	while ((read_bytes = read(fd, buffer_for_read, BUFF_SIZE)) > 0)
	{
		buffer_for_read[read_bytes] = '\0';
		//printf("I'M BUFFER: %s\n", buffer_for_read);
		if (!(result_string))
		{
			// printf("---->>>I'M IN THE 1ST TIME --->>>\n");
			if (!(result_string = malloc(sizeof(char) * read_bytes + 1)))
				return (NULL);
			ft_bzero(result_string, read_bytes + 1);
			ft_memcpy(result_string, buffer_for_read, read_bytes);
			//printf("%s\n", result_string );
		}
		else
		{
			// printf("--->>>>i'm in join!!!\n");
			//printf("result_string HERE:%s\n", result_string );
			result_string = join_me(result_string, buffer_for_read);
			//printf("AFTER_CONCATENATION: %s\n", result_string );
			//printf("\n" );
		}
		
	}
	//printf("len of result str: %zu\n", ft_strlen (result_string));
	res_str_len = ft_strlen (result_string);
	result_string[res_str_len] = '\0';
	//printf("%c\n", result_string[res_str_len - 1] );

	return(result_string);
	
}


int get_next_line(const int fd, char **line)
{
	static char	*result_string;
	//printf("The value of FD: %i\n", fd );
	//printf("BUFF_SIZE = %i\n", BUFF_SIZE );
	if (fd == -1)
		return (0);
	result_string = i_am_for_reading(fd, result_string);
	//printf("\n");
	//printf("I AM HERE --->>>\n");
	printf("%s\n", result_string );
	
	free(result_string);
	// system("leaks /a.out");
	// while (1){};

	return (0);
}
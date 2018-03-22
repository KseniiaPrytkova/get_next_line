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
		if (!(result_string))
		{
			if (!(result_string = malloc(sizeof(char) * read_bytes + 1)))
				return (NULL);
			ft_bzero(result_string, read_bytes + 1);
			ft_memcpy(result_string, buffer_for_read, read_bytes);
		}
		else
			result_string = join_me(result_string, buffer_for_read);
	}
	res_str_len = ft_strlen (result_string);
	result_string[res_str_len] = '\0';
	return(result_string);
}

char	*string_sub(char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	string_len;
	int		j;

	j = 0;
	string_len = ft_strlen(s);
	if (s && start < string_len + 1 && len < string_len + 1)
	{
		if ((substring = malloc(sizeof(char) * len + 1)) == NULL)
			return (NULL);
		while (start < string_len && j < len)
		{
			substring[j] = s[start];
			start++;
			j++;
		}
		substring[j] = '\0';
	}
	free (s);
	return (substring);
}

int get_next_line(const int fd, char **line)
{
	static char	*result_string[4864];
	int			counter;
	char		*buffer;
	int			str_len;

	if (fd == -1)
		return (0);
	if (!result_string[fd])
		result_string[fd] = i_am_for_reading(fd, result_string[fd]);
	str_len = ft_strlen(result_string[fd]);
	counter = 0;
	while (*result_string[fd] != '\n' && *result_string[fd] != '\0')
	{	
		result_string[fd]++;
		counter++;
	}
	result_string[fd] -= counter;
	buffer = ft_strncpy(ft_strnew(counter), result_string[fd], counter);
	result_string[fd] = string_sub(result_string[fd], counter + 1, (str_len - counter));
	*line = buffer;
	free(buffer);
	return (0);
}
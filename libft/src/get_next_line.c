/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayd <sayd@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:05:56 by cdumais           #+#    #+#             */
/*   Updated: 2023/04/19 23:04:15 by sayd             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	join_buffers(char **line, char *buffer)
{
	char	*temp;
	size_t	line_len;
	char	*buffer_end;

	line_len = ft_strlen(*line);
	if (ft_strlen(buffer) <= 0)
		return (0);
	buffer_end = ft_strchr(buffer, '\n');
	if (!buffer_end)
		buffer_end = ft_strchr(buffer, '\0');
	else
		buffer_end++;
	temp = *line;
	*line = ft_calloc(line_len + (buffer_end - buffer) + 1, 1);
	if (!line)
		return (0);
	ft_strlcpy(*line, temp, line_len + 1);
	ft_strlcat(*line, buffer, line_len + (buffer_end - buffer) + 1);
	ft_strlcpy(buffer, buffer_end, ft_strlen(buffer_end) + 1);
	free(temp);
	if (ft_strchr(*line, '\n'))
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	input_buffer[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0 && !join_buffers(&line, input_buffer))
	{
		bytes_read = read(fd, input_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		input_buffer[bytes_read] = '\0';
	}
	return (line);
}

/*
#include "get_next_line.h"

int main(void)
{
	int	fd_1;
	char *str_2;
	str_2 = "123";

	fd_1 = open("text1.txt", O_RDONLY);
	// while (str_2)
	// {	
	// 	str_2 = get_next_line(fd_1);
	// 	printf("%s", str_2);
	// 	free(str_2);
	// }
	
		printf("%s\n", get_next_line(fd_1));
	close (fd_1);
}
*/

/*
bonus
*/
/*
char	*get_next_line(int fd)
{
	static char	fd_states[MAX_OPEN][BUFFER_SIZE + 1];
	char		*line;
	char		*buffer;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_OPEN)
		return (NULL);
	buffer = fd_states[fd];
	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0 && !join_buffers(&line, buffer))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (line)
				free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
	}
	return (line);
}
*/
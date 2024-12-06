/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:39:34 by jode-jes          #+#    #+#             */
/*   Updated: 2024/11/19 13:29:29 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// GENERAL EXPLANATION:
// 1 - The get_next_line function takes a file descriptor (fd) as an
// argument and initializes a static buffer variable (stash) to
// store the data read from the file.
// 2 - It first performs some basic error checks to ensure that the
// file descriptor is valid (fd >= 0) and the buffer size is positive
//(BUFFER_SIZE > 0). If any of these conditions are not met, it returns 0
// or NULL to indicate an error.
// 3 - Next, it calls the ft_read_line function, passing the file descriptor
// and the stash. The ft_read_line function reads data from the file
// into the buffer until it encounters a newline character or reaches the
// end of the file.
// 4 - Once the data is read into the stash, the ft_get_line function is called,
//	passing the stash as an argument.
// This function extracts a line from the stah up to the newline character or
// the end of the buffer. It dynamically allocates memory for the extracted line
// and copies the characters from the stash to the line.
// 5 - After extracting the line, the ft_new_line function is called,
//	passing again the stash as an argument. This function extracts the
// remaining data after the newline character from the stash.
// It dynamically allocates memory for the remaining data,
//	copies the characters to a new string (the newline),
// and frees the memory previously allocated for the stash.
// 6 - The extracted line is returned from the get_next_line function.
// 7 - When the get_next_line function is called again,
//	it resumes from where it left off,
// using the static variable (stash) to retrieve the next line from the file.
// The static stash retains the remaining data from the previous call,
//	and any new data read from the file is appended to it.
// This allows the function to continue reading lines from the file until
// the end is reached.
// 8- The process continues until there are no more lines to read or an
// error occurs.
//
// It's important to note that this implementation assumes that the file
// being read contains lines terminated by newline characters ('\n').
// The code reads and processes the file one line at a time,
// and each call to get_next_line retrieves the next line from the file.
// The static buffer retains any remaining data after the last newline
// character, ensuring that it's included in the subsequent calls to
// get_next_line.

#include "libft.h"

char	*ft_read_line(int fd, char *stash)
{
	char	*buf;
	int		nbytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	nbytes_read = 1;
	while (!ft_gnl_strchr(stash, '\n') && nbytes_read != 0)
	{
		nbytes_read = read(fd, buf, BUFFER_SIZE);
		if (nbytes_read == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[nbytes_read] = '\0';
		if (!buf)
			return (NULL);
		stash = ft_gnl_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		line = (char *)malloc(sizeof(char) * (i + 1));
	else
		line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_line(char *stash)
{
	int		i;
	int		j;
	char	*newline;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i] || !stash[i + 1])
	{
		free(stash);
		return (NULL);
	}
	newline = (char *)malloc(sizeof(char) * (ft_gnl_strlen(stash) - i + 1));
	if (!newline)
		return (NULL);
	i++;
	while (stash[i])
		newline[j++] = stash[i++];
	newline[j] = '\0';
	free(stash);
	return (newline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_read_line(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_new_line(stash);
	return (line);
}

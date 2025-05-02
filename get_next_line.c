/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 13:15:04 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/02 19:00:10 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_lines(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read != 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./get_next_line <file>\n", 2);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		ft_putstr_fd(line, 1);
		free(line);
	}
	close(fd);
	return (0);
}


/*
Variables gnl :
buff
static tmp
keep tmp
line

fonctions :

memcpy
strchr
strjoin

read buff > memcpy buff to static tmp > free buff > strchr '\n' >read buff > memcpy static tmp to keep_tmp > free static tmp > strjoin(static tmp, keep_tmp)
free buff and keep_tmp > strchr '\n'
if \n > copier dans keep_tmp ce qu'il y a apres \n > memcpy ce qu'il y a avant \n dans line > free static tmp > memcpy keep_tmp to static tmp > return line + '\0'
*/
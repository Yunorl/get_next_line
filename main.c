/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnahon <dnahon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:11:14 by dnahon            #+#    #+#             */
/*   Updated: 2025/05/05 17:20:17 by dnahon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*string;

	string = NULL;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file");
		return (1);
	}
	string = get_next_line(fd);
	while (string)
	{
		printf("%s", string);
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:01:22 by drobert-          #+#    #+#             */
/*   Updated: 2022/02/23 18:21:44 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	assign_read(int *amount_read, char **read_buff, int fd)
{
	*read_buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!*read_buff)
		return (0);
	*amount_read = read(fd, *read_buff, BUFFER_SIZE);
	if (*amount_read == 0)
	{
		free(*read_buff);
		return (0);
	}
	return (*amount_read);
}

void	read_file(t_buffer **buff, int fd, int *i)
{
	int	amount_read;

	amount_read = 1;
	while (amount_read != 0)
	{
		if (++(*i) == (*buff)->size)
			amount_read = read_buffer(*buff, fd);
		if (*((*buff)->buff + (*i)) == '\n')
			break ;
	}
}

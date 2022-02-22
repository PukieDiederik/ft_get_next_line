/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:53:20 by drobert-          #+#    #+#             */
/*   Updated: 2022/02/22 16:23:30 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	clear_buff(t_buffer *buff)
{
	free(buff->buff);
	buff->buff = 0;
	buff->size = 0;
}

int	read_buffer(t_buffer *buff, int fd)
{
	char	*read_buff;
	char	*new_buff;
	int		amount_read;
	int		i;

	read_buff = malloc(BUFFER_SIZE * sizeof(char));
	if (!read_buff)
		return (-1);
	amount_read = read(fd, read_buff, BUFFER_SIZE);
	if (amount_read == 0)
	{
		free(read_buff);
		return (0);
	}
	new_buff = malloc((amount_read + buff->size) * sizeof(char));
	if (new_buff == 0 || amount_read == 0)
	{
		free(read_buff);
		return (0);
	}
	i = -1;
	while (++i < buff->size && buff->buff)
		*(new_buff + i) = *(buff->buff + i);
	i = -1;
	while (++i < amount_read)
		*(new_buff + i + buff->size) = *(read_buff + i);
	buff->size += amount_read;
	free(read_buff);
	free(buff->buff);
	buff->buff = new_buff;
	return (amount_read);
}

//clears a line in the buffer
//if the buffer will become empty as a result, return (0);
void	clear_line_buffer(t_buffer *buff)
{
	int		i;
	int		j;
	char	*new_buff;

	if (!buff->buff)
		return ;
	i = 0;
	while (i < buff->size && *(buff->buff + i) != '\n')
		i++;
	i++;
	if (i >= buff->size)
		clear_buff(buff);
	else
	{
		new_buff = malloc(buff->size - i);
		if (!new_buff)
			return ;
		j = -1;
		while (++j < buff->size - i)
			*(new_buff + j) = *(buff->buff + i + j);
		buff->size -= i;
		free(buff->buff);
		buff->buff = new_buff;
	}
}

char	*get_line(t_buffer *buff, int fd)
{
	int		i;
	char	*str;
	int		amount_read;

	if (buff->buff == 0)
		return (0);
	i = 0;
	amount_read = 1;
	while (*(buff->buff + i) != '\n' && amount_read != 0)
	{
		if (i == buff->size)
			amount_read = read_buffer(buff, fd);
		else
			i++;
	}
	str = (char *)malloc((i + 2) * sizeof(*str));
	if (str == 0)
		return (0);
	*(str + ++i) = 0;
	while (--i >= 0)
		*(str + i) = *(buff->buff + i);
	clear_line_buffer(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_buffer	buff = {.size = 0, .buff = 0};

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (buff.buff == 0)
	{
		read_buffer(&buff, fd);
		if (buff.buff == 0)
			return (0);
	}
	return (get_line(&buff, fd));
}
/*
int main()
{
	char *str = 0;
	while ((str = get_next_line(0)))
		printf("%s", str);
}*/

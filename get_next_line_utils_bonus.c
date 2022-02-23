/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:35:13 by drobert-          #+#    #+#             */
/*   Updated: 2022/02/23 16:42:40 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buffer	*get_buffer_from_fd(int fd, t_list **start)
{
	t_list		*cur;
	t_list		*new;
	t_buffer	*new_buff;

	cur = *start;
	while (cur && cur->fd != fd)
		cur = cur->next;
	if (!cur)
	{
		new = malloc(sizeof(t_list));
		if (new == 0)
			return (0);
		new_buff = malloc(sizeof(t_buffer));
		if (new_buff == 0)
		{
			free(new);
			return (0);
		}
		new_buff->buff = 0;
		new_buff->size = 0;
		new->buff = new_buff;
		new->fd = 0;
		new->next = *start;
		*start = new;
		return (new->buff);
	}
	return (cur->buff);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:50:18 by drobert-          #+#    #+#             */
/*   Updated: 2022/02/23 16:45:46 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//includes
# include <unistd.h>
# include <stdlib.h>

//structs
typedef struct s_buff
{
	int		size;
	char	*buff;
}	t_buffer;

typedef struct s_list
{
	int				fd;
	struct s_buff	*buff;
	struct s_list	*next;
}	t_list;

//functions
char	*get_next_line(int fd);
t_buffer    *get_buffer_from_fd(int fd, t_list **start);
#endif

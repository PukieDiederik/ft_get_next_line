/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:50:18 by drobert-          #+#    #+#             */
/*   Updated: 2022/03/22 10:29:55 by drobert-         ###   ########.fr       */
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

//functions
char	*get_next_line(int fd);

#endif

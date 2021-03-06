/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drobert- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:52:42 by drobert-          #+#    #+#             */
/*   Updated: 2022/03/22 10:31:50 by drobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

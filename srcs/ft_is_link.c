/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 02:49:01 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 02:51:57 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	ft_is_link(char *str)
{
	char	**rooms;
	int		room_n;

	room_n = 0;
	rooms = ft_strsplit(str, '-');
	while (rooms[room_n])
		room_n++;
	if (room_n == 2 && (ft_strlen(rooms[0]) + ft_strlen(rooms[1])\
	+ 1 == ft_strlen(str)))
	{
		ft_free_char_doble(rooms);
		return (1);
	}
	ft_free_char_doble(rooms);
	return (0);
}

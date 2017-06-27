/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 00:20:46 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/26 18:36:10 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

static char ft_is_room_helper_a(char *str, char **rooms)
{
	int n_room;

	n_room = 0;
	while (rooms[n_room])
		n_room++;
	if (n_room != 3 || ((ft_strlen(rooms[0]) + ft_strlen(rooms[1]) +\
	ft_strlen(rooms[2]) + 2) != ft_strlen(str)) || !ft_strncmp(rooms[0], "L",\
	1) || !ft_strncmp(rooms[0], "#", 1))
		return (0);
	return (1);
}

static char ft_is_room_helper_b(char **rooms)
{
	int n_room;
	int num;
	char *num_str;

	n_room = 1;
	while (n_room < 3)
	{
		num = ft_atoi(rooms[n_room]);
		num_str = ft_itoa_base(num, 10);
		if (ft_strcmp(num_str, rooms[n_room]))
		{
			ft_memdel((void **)&num_str);
			return (0);
		}
		ft_memdel((void **)&num_str);
		n_room++;
	}
	return (1);
}

char ft_is_room(char *str)
{
	char **rooms;

	rooms = ft_strsplit(str, ' ');
	if (!ft_is_room_helper_a(str, rooms) || !ft_is_room_helper_b(rooms))
	{
		ft_free_char_doble(rooms);
		return (0);
	}
	ft_free_char_doble(rooms);
	return (1);
}

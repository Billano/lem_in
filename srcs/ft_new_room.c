/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 20:27:55 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 21:09:02 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_room *ft_new_room(t_list_s *the_rooms, char *src, t_room_list room_list, int i)
{
	t_room *room;
	char **info;

	room = 0;
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	while (the_rooms)
	{
		info = ft_strsplit(the_rooms->data, ' ');
		if (!ft_strcmp(info[0], src))
		{
			room->name = ft_strdup(info[0]);
			room->dest = i;
			room->x = ft_atoi(info[1]);
			room->y = ft_atoi(info[2]);
			room->next = 0;
			room->weight = ft_room_weight(room_list.x, room_list.y, room->x, room->y);
			ft_free_char_doble(info);
			return (room);
		}
		ft_free_char_doble(info);
		the_rooms = the_rooms->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 00:56:54 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 02:05:27 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	ft_valid_room(t_list_s *rooms, char *new_room)
{
	char	**new_room_info;
	char	**tmp_room;
	int		i;

	i = 0;
	new_room_info = ft_strsplit(new_room, ' ');
	while (rooms)
	{
		tmp_room = ft_strsplit(rooms->data, ' ');
		if (!ft_strcmp(tmp_room[0], new_room_info[0]) ||\
		(!ft_strcmp(tmp_room[1], new_room_info[1]) &&\
		!ft_strcmp(tmp_room[2], new_room_info[2])))
		{
			ft_free_char_doble(tmp_room);
			ft_free_char_doble(new_room_info);
			return (0);
		}
		ft_free_char_doble(tmp_room);
		rooms = rooms->next;
	}
	ft_free_char_doble(new_room_info);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 00:13:02 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 02:17:06 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_list_s *ft_the_rooms(t_list_s **map)
{
	t_list_s *tmp;
	t_list_s *rooms;

	tmp = 0;
	rooms = 0;
	tmp = *map;
	while (tmp)
	{
		if (ft_strncmp(tmp->data, "#", 1) && ft_strncmp(tmp->data, "L", 1) &&\
		ft_is_room(tmp->data))
		{
			if (!ft_valid_room(rooms, tmp->data))
			{
				ft_free_list_s(rooms);
				return (0);
			}
			ft_list_push_back_s(&rooms, tmp->data);
		}
		tmp = tmp->next;
	}
	return (rooms);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 02:52:26 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 03:01:37 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	ft_valid_link(char *link, t_list_s *rooms)
{
	char	**links;
	char	**room_info;
	char	room_one;
	char	room_two;

	room_one = 0;
	room_two = 0;
	links = ft_strsplit(link, '-');
	while (rooms)
	{
		room_info = ft_strsplit(rooms->data, ' ');
		if (!ft_strcmp(room_info[0], links[0]))
			room_one = 1;
		if (!ft_strcmp(room_info[0], links[1]))
			room_two = 1;
		ft_free_char_doble(room_info);
		rooms = rooms->next;
	}
	ft_free_char_doble(links);
	if (!room_one || !room_two)
		return (0);
	return (1);
}

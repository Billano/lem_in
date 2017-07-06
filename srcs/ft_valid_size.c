/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 23:48:15 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/04 02:55:15 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	ft_valid_size(t_list_s *map)
{
	t_list_s *rooms;
	t_list_s *links;
	t_list_s *comments;

	rooms = 0;
	links = 0;
	comments = 0;
	rooms = ft_the_rooms(&map);
	links = ft_the_links(&map, rooms);
	comments = ft_comments(&map);
	if (!ft_number_of_ants(&map) || !rooms || !links || !comments ||\
	(ft_list_size_s(rooms) + ft_list_size_s(links) + ft_list_size_s(comments)\
	+ 1 != ft_list_size_s(map)))
	{
		ft_free_list_s(rooms);
		ft_free_list_s(comments);
		ft_free_list_s(links);
		return (0);
	}
	ft_free_list_s(rooms);
	ft_free_list_s(comments);
	ft_free_list_s(links);
	return (1);
}

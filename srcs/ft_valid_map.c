/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 23:43:26 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/03 22:43:06 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	ft_valid_map(t_list_s *map)
{
	t_graph		*graph;
	t_list_s	*rooms;
	t_list_s	*links;

	if (!ft_valid_size(map))
		return (0);
	rooms = ft_the_rooms(&map);
	links = ft_the_links(&map, rooms);
	graph = ft_graph_parser(rooms, links);
	ft_free_list_s(rooms);
	ft_free_list_s(links);
	if (!ft_valid_solution(graph, map))
	{
		ft_free_graph(graph);
		return (0);
	}
	ft_free_graph(graph);
	return (1);
}

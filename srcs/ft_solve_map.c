/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:37:29 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/05 16:13:03 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_solve_map(t_list_s *map, char *start_name, char *end_name)
{
	t_list_s	*rooms;
	t_list_s	*links;
	t_graph		*graph;
	int			*path;
	t_list_s	*camino;

	rooms = ft_the_rooms(&map);
	links = ft_the_links(&map, rooms);
	graph = ft_graph_parser(rooms, links);
	camino = 0;
	path = ft_dijkstra_path(graph, ft_graph_index_extract(graph, start_name));
	ft_push_path(graph, path, ft_graph_index_extract(graph, end_name), &camino);
	ft_print_ants(ft_number_of_ants(&map), camino);
	ft_free_list_s(rooms);
	ft_free_list_s(links);
	ft_free_graph(graph);
	ft_free_list_s(camino);
	ft_memdel((void **)&path);
}

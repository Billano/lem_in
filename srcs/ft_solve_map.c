/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:37:29 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/26 20:03:01 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void ft_solve_map(t_list_s* map)
{
	int ants;
	t_list_s *rooms;
	t_list_s *links;
	t_graph *graph;

	ants = ft_number_of_ants(&map);
	rooms = ft_the_rooms(&map);
	links = ft_the_links(&map, rooms);
	graph = ft_graph_parser(rooms, links);
	printf("\nImprimiendo el graph:\n");
	ft_print_graph(graph);

}

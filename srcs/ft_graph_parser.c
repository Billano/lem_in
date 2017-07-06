/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:26:59 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 21:11:17 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_graph	*ft_graph_parser(t_list_s *rooms, t_list_s *links)
{
	t_graph	*graph;
	char	**l_rooms;

	graph = 0;
	graph = ft_graph_create_adj(rooms, ft_list_size_s(rooms));
	while (links)
	{
		l_rooms = ft_strsplit(links->data, '-');
		graph = ft_graph_add_edge(graph, rooms, l_rooms[0], l_rooms[1]);
		links = links->next;
		ft_free_char_doble(l_rooms);
	}
	return (graph);
}

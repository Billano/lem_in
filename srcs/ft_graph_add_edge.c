/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_add_edge.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 20:25:24 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/05 16:16:05 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_graph	*ft_graph_add_edge(t_graph *graph, t_list_s *the_rooms, char *src,\
		char *dest)
{
	t_room	*room;
	int		src_n;
	int		dest_n;

	src_n = ft_graph_index_extract(graph, src);
	dest_n = ft_graph_index_extract(graph, dest);
	room = ft_new_room(the_rooms, dest, graph->arr[src_n], dest_n);
	room->next = graph->arr[src_n].head;
	graph->arr[src_n].head = room;
	room = ft_new_room(the_rooms, src, graph->arr[dest_n], src_n);
	room->next = graph->arr[dest_n].head;
	graph->arr[dest_n].head = room;
	return (graph);
}

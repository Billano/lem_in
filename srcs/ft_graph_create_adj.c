/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_create_adj.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 19:35:07 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 20:24:44 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_graph *ft_graph_create_adj(t_list_s *rooms, int n)
{
	t_graph *graph;
	int i;
	char **room;

	i = 0;
	graph = 0;
	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (0);
	if (!(graph->arr = (t_room_list *)malloc(sizeof(t_room_list) * n)))
		return (0);
	while (i < n)
	{
		room = ft_strsplit(rooms->data, ' ');
		graph->arr[i].name = ft_strdup(room[0]);
		graph->arr[i].head = 0;
		graph->arr[i].x = ft_atoi(room[1]);
		graph->arr[i].y = ft_atoi(room[2]);
		i++;
		rooms = rooms->next;
		ft_free_char_doble(room);
	}
	graph->n = n;
	return (graph);
}

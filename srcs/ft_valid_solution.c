/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_solution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 14:43:25 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 22:15:35 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char ft_valid_solution(t_graph *graph, t_list_s *map)
{
	char *start_name;
	char *end_name;
	int idx;

	idx = 0;
	start_name = ft_start(&map);
	end_name = ft_end(&map);
	if (!ft_dijkstra(graph, ft_graph_index_extract(graph, start_name),\
	ft_graph_index_extract(graph, end_name)))
	{
		ft_memdel((void **)&start_name);
		ft_memdel((void **)&end_name);
		return (0);
	}
	else
	{
		ft_memdel((void **)&start_name);
		ft_memdel((void **)&end_name);
		return (1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 02:32:59 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/26 21:53:04 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void ft_print_graph(t_graph *graph)
{
	int i;
	t_room *room;

	i = 0;
	room = 0;
	while (i < graph->n)
	{
		room = graph->arr[i].head;
		printf("\nAd list of vertex %s\n head, dest: %d", graph->arr[i].name, i);
		while (room)
		{
			printf("-> %s, weight: %d, dest: %d", room->name, room->weight, room->dest);
			room = room->next;
		}
		i++;
	}
}

void ft_print_arr(int *dist, int n, t_graph *graph)
{
	int i;

	i = 0;
	printf("\n\nname\t\tvertex\t\tdistance from source\n");
	while (i < n)
	{
		printf("%s\t\t %d \t \t %d\n", graph->arr[i].name, i, dist[i]);
		i++;
	}
}

// void 	ft_solve_map(t_list_s *map, t_list_s *rooms, t_list_s *links)
// {
//
//
// }

int main()
{
	t_list_s *map;

	map = ft_get_map();
	if (!ft_valid_map(map))
	{
		ft_putstr("ERROR");
		return (0);
	}
	ft_print_map(map);
	ft_solve_map(map);
	return (0);
}

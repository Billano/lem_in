/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 21:11:22 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/04 03:06:36 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_free_graph(t_graph *graph)
{
	int i;

	i = 0;
	while (i < graph->n)
	{
		free(graph->arr[i].name);
		ft_free_t_room(graph->arr[i].head);
		i++;
	}
	free(graph->arr);
	free(graph);
}

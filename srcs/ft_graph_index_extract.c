/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph_index_extract.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:09:53 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 21:10:15 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int ft_graph_index_extract(t_graph *graph, char *src)
{
	int i;

	i = 0;
	while (i < graph->n)
	{
		if (!ft_strcmp(graph->arr[i].name, src))
			break ;
		i++;
	}
	return (i);
}

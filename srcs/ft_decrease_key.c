/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decrease_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:22:36 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/27 23:35:49 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_decrease_key(t_min_heap *min_heap, int v, int dist)
{
	int i;

	i = min_heap->pos[v];
	min_heap->arr[i]->dist = dist;
	while (i && min_heap->arr[i]->dist < min_heap->arr[(i - 1) / 2]->dist)
	{
		min_heap->pos[min_heap->arr[i]->v] = (i - 1) / 2;
		min_heap->pos[min_heap->arr[(i - 1) / 2]->v] = i;
		ft_swap_min_heap_node(&min_heap->arr[i], &min_heap->arr[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

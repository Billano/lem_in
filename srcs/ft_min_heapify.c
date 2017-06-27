/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_heapify.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:28:11 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 22:28:45 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void ft_min_heapify(t_min_heap *min_heap, int idx)
{
	int smallest;
	int left;
	int right;
	t_min_heap_node *smallest_node;
	t_min_heap_node *idx_node;

	left = 2 * idx + 1;
	right = 2 * idx + 2;
	smallest_node = 0;
	idx_node = 0;
	smallest = idx;
	if (left < min_heap->size && min_heap->arr[left]->dist < min_heap->arr[smallest]->dist)
		smallest = left;
	if (right < min_heap->size && min_heap->arr[right]->dist < min_heap->arr[smallest]->dist)
		smallest = right;
	if (smallest != idx)
	{
		smallest_node = min_heap->arr[smallest];
		idx_node = min_heap->arr[idx];
		min_heap->pos[smallest_node->v] = idx;
		min_heap->pos[idx_node->v] = smallest;
		ft_swap_min_heap_node(&min_heap->arr[smallest], &min_heap->arr[idx]);
		ft_min_heapify(min_heap, smallest);
	}
}

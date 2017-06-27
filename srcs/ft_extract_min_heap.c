/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_min_heap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:26:50 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 22:27:21 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_min_heap_node *ft_extract_min_heap(t_min_heap *min_heap)
{
	t_min_heap_node *root;
	t_min_heap_node *last_node;

	if (ft_is_heap_empty(min_heap))
		return (0);
	root = 0;
	last_node = 0;
	root = min_heap->arr[0];
	last_node = min_heap->arr[min_heap->size - 1];
	min_heap->arr[0] = last_node;
	min_heap->pos[root->v] = min_heap->size - 1;
	min_heap->pos[last_node->v] = 0;
	--min_heap->size;
	ft_min_heapify(min_heap, 0);
	return (root);
}

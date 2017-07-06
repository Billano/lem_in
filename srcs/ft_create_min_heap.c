/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_min_heap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:18:12 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/29 01:45:17 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_min_heap	*ft_create_min_heap(int capacity)
{
	t_min_heap *min_heap;

	if (!(min_heap = (t_min_heap *)malloc(sizeof(t_min_heap))))
		return (0);
	min_heap->pos = (int *)malloc(sizeof(int) * capacity);
	min_heap->size = 0;
	min_heap->capacity = capacity;
	min_heap->arr = (t_min_heap_node **)malloc(sizeof(t_min_heap_node *)\
	* capacity);
	return (min_heap);
}

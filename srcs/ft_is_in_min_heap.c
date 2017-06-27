/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_in_min_heap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:29:31 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 22:29:57 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char ft_is_in_min_heap(t_min_heap *min_heap, int v)
{
	if (min_heap->pos[v] < min_heap->size)
		return (1);
	return (0);
}

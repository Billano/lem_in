/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_min_heap_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:20:53 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 22:21:10 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_min_heap_node *ft_new_min_heap_node(int v, int dist)
{
	t_min_heap_node *node;

	if (!(node = (t_min_heap_node *)malloc(sizeof(t_min_heap_node))))
		return (0);
	node->v = v;
	node->dist = dist;
	return (node);
}

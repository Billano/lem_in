/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_min_heap_node.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:23:37 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 22:23:50 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_swap_min_heap_node(t_min_heap_node **a, t_min_heap_node **b)
{
	t_min_heap_node *t;

	t = *a;
	*a = *b;
	*b = t;
}

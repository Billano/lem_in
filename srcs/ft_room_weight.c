/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_weight.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:08:06 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 21:08:53 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int	ft_room_weight(int src_x, int src_y, int dest_x, int dest_y)
{
	int x;
	int y;
	int c;

	x = dest_x - src_x;
	y = dest_y - src_y;
	c = (x * x) + (y * y);
	return (ft_sqrt(c));
}

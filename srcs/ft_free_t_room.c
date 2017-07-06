/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_t_room.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 03:00:38 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/04 03:07:04 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_free_t_room(t_room *room)
{
	t_room	*tmp;

	tmp = 0;
	while (room)
	{
		tmp = room->next;
		ft_memdel((void **)&room->name);
		free(room);
		room = tmp;
	}
}

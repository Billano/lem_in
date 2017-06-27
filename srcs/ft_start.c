/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:26:04 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 21:34:46 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char *ft_start(t_list_s **map)
{
	t_list_s *tmp;
	char **start_name;
	char *str;

	tmp = 0;
	tmp = *map;
	while (tmp && ft_strcmp(tmp->data, "##start"))
		tmp = tmp->next;
	while (tmp && !ft_strncmp(tmp->data, "#", 1) && !ft_is_room(tmp->data))
		tmp = tmp->next;
	if (tmp && ft_is_room(tmp->data))
	{
		start_name = ft_strsplit(tmp->data, ' ');
		str = ft_strdup(start_name[0]);
		ft_free_char_doble(start_name);
		return (str);
	}
	return (0);
}

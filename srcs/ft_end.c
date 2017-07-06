/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:30:01 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/03 22:23:35 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	*ft_end(t_list_s **map)
{
	t_list_s	*tmp;
	char		**end_name;
	char		*str;

	tmp = 0;
	tmp = *map;
	while (tmp && ft_strcmp(tmp->data, "##end"))
		tmp = tmp->next;
	while (tmp && !ft_strncmp(tmp->data, "#", 1) && !ft_is_room(tmp->data))
		tmp = tmp->next;
	if (tmp && ft_is_room(tmp->data))
	{
		end_name = ft_strsplit(tmp->data, ' ');
		str = ft_strdup(end_name[0]);
		ft_free_char_doble(end_name);
		return (str);
	}
	return (ft_strdup(""));
}

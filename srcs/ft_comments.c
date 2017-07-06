/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comments.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 03:06:23 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 03:10:55 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_list_s	*ft_comments(t_list_s **map)
{
	t_list_s	*tmp;
	t_list_s	*comments;
	char		start;
	char		end;

	tmp = *map;
	comments = 0;
	start = 0;
	end = 0;
	while (tmp)
	{
		if (!ft_strcmp(tmp->data, "##start"))
			start = 1;
		if (!ft_strcmp(tmp->data, "##end"))
			end = 1;
		if (!ft_strncmp(tmp->data, "#", 1))
			ft_list_push_back_s(&comments, tmp->data);
		tmp = tmp->next;
	}
	if (!start || !end)
	{
		ft_free_list_s(comments);
		return (0);
	}
	return (comments);
}

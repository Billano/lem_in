/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 02:26:51 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 02:52:17 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_list_s	*ft_the_links(t_list_s **maps, t_list_s *rooms)
{
	t_list_s	*tmp;
	t_list_s	*list;

	tmp = 0;
	tmp = *maps;
	list = 0;
	while (tmp)
	{
		if (ft_is_link(tmp->data))
		{
			if (!ft_valid_link(tmp->data, rooms))
			{
				ft_free_list_s(list);
				return (0);
			}
			ft_list_push_back_s(&list, tmp->data);
		}
		tmp = tmp->next;
	}
	return (list);
}

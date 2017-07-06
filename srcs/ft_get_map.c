/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 23:33:06 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/03 22:17:45 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

t_list_s	*ft_get_map(void)
{
	t_list_s	*map;
	int			ret;
	char		*buf;

	map = 0;
	while ((ret = get_next_line(0, &buf)) > 0)
	{
		ft_list_push_back_s(&map, buf);
		ft_memdel((void **)&buf);
	}
	ft_memdel((void **)&buf);
	return (map);
}

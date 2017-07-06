/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_of_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 23:58:42 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 00:02:25 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int	ft_number_of_ants(t_list_s **map)
{
	t_list_s	*tmp;
	char		*num_str;
	int			num;

	tmp = 0;
	tmp = *map;
	while (!ft_strncmp(tmp->data, "#", 1))
		tmp = tmp->next;
	num = ft_atoi(tmp->data);
	num_str = ft_itoa_base(num, 10);
	if (!ft_strcmp(num_str, tmp->data))
	{
		ft_memdel((void **)&num_str);
		return (num);
	}
	ft_memdel((void **)&num_str);
	return (0);
}

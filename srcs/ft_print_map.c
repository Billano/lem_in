/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 18:41:38 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/29 20:20:01 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_print_map(t_list_s *map)
{
	while (map)
	{
		ft_printf("%s\n", map->data);
		map = map->next;
	}
	ft_putchar('\n');
}

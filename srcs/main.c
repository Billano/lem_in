/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 02:32:59 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/05 16:27:20 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int	main(void)
{
	t_list_s	*map;
	char		*start_name;
	char		*end_name;

	map = 0;
	map = ft_get_map();
	if (!ft_valid_map(map))
	{
		ft_putstr("ERROR");
		ft_free_list_s(map);
		return (0);
	}
	ft_print_map(map);
	start_name = ft_start(&map);
	end_name = ft_end(&map);
	ft_solve_map(map, start_name, end_name);
	ft_memdel((void **)&start_name);
	ft_memdel((void **)&end_name);
	ft_free_list_s(map);
	return (0);
}

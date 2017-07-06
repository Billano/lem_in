/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:49:36 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/05 16:07:16 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_print_ants(int n, t_list_s *path)
{
	int		i;
	int		out_lim;
	char	**camino;
	int		j;
	int		x;

	out_lim = ft_list_size_s(path) + n - 1;
	camino = ft_list_s_to_char_dob(path);
	i = 1;
	while (i <= out_lim)
	{
		j = i - 1;
		if (j >= ft_list_size_s(path))
			j = ft_list_size_s(path) - 1;
		while (j >= 0)
		{
			x = i - j;
			if (x <= n)
				ft_printf("L%d-%s ", x, camino[j]);
			j--;
		}
		ft_putstr("\n");
		i++;
	}
	ft_free_char_doble(camino);
}

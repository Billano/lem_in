/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:13:03 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/03 20:46:44 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_free_list_s(t_list_s *list)
{
	t_list_s *tmp;

	tmp = 0;
	while (list)
	{
		tmp = list->next;
		ft_memdel((void **)&(list->data));
		ft_memdel((void **)&list);
		list = tmp;
	}
}

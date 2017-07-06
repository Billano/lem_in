/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:42:17 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/29 16:46:48 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void	ft_push_path(t_graph *graph, int *path, int j, t_list_s **rooms)
{
	if (path[j] == -1)
		return ;
	ft_push_path(graph, path, path[j], rooms);
	ft_list_push_back_s(rooms, graph->arr[j].name);
}

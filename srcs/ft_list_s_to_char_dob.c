/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_s_to_char_dob.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:15:35 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/03 21:59:29 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

char	**ft_list_s_to_char_dob(t_list_s *list)
{
	char	**str;
	int		i;
	int		n;

	n = ft_list_size_s(list);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	i = 0;
	while (i < n)
	{
		str[i] = ft_strdup(list->data);
		list = list->next;
		i++;
	}
	str[i] = 0;
	return (str);
}

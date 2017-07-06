/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 20:34:24 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/03 22:08:02 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lst_to_s(t_lst *lst)
{
	char		*str;
	size_t		i;
	t_lst		*tmp;
	t_lst		*head;

	tmp = lst;
	i = 0;
	str = ft_strnew(ft_lst_len(tmp));
	while (tmp)
	{
		str[i++] = tmp->data;
		head = tmp;
		tmp = tmp->next;
		ft_memdel((void **)&head);
	}
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:20:21 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/22 16:37:37 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEM_IN_H
# define FT_LEM_IN_H

# include "./libftprintf.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <grp.h>
# include <pwd.h>
# include <time.h>


typedef struct				s_room
{
	char					*name;
	int dest;
	int weight;
	int x;
	int y;
	struct s_room	*next;
}							t_room;

typedef struct s_room_list
{
	t_room *head;
	char *name;
	int x;
	int y;
	// int dest;
}							t_room_list;

typedef struct s_graph
{
	int		n;
	t_room_list *arr;
}							t_graph;

typedef struct s_min_heap_node
{
	int v;
	int dist;
}						t_min_heap_node;

typedef struct s_min_heap
{
	int size;
	int capacity;
	int *pos;
	t_min_heap_node **arr;
}						t_min_heap;

// t_min_heap_node *ft_new_min_heap_node()



int	ft_number_of_ants(t_list_s **map);
t_list_s *ft_comments(t_list_s **map);
char ft_is_room(char *str);
char *ft_start(t_list_s **map);
char *ft_end(t_list_s **map);
t_list_s *ft_the_rooms(t_list_s **map);
char ft_is_link(char *str);
t_list_s *ft_the_links(t_list_s **maps);
char ft_valid_map(t_list_s *maps, t_list_s *comments, t_list_s *rooms, t_list_s *links);
t_graph *ft_graph_create_adj(t_list_s *rooms, int n);
t_room *ft_new_room(t_list_s *the_rooms, char *src, t_room_list room_list, int i);
t_graph *ft_graph_add_edge(t_graph *graph, t_list_s *the_rooms, char *src, char *dest);
t_graph *ft_graph_parser(t_list_s *rooms, t_list_s *links);


#endif

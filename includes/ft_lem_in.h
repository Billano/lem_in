/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:20:21 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/05 16:55:04 by eurodrig         ###   ########.fr       */
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

typedef struct		s_room
{
	char			*name;
	int				dest;
	int				weight;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_room_list
{
	t_room			*head;
	char			*name;
	int				x;
	int				y;
}					t_room_list;

typedef struct		s_graph
{
	int				n;
	t_room_list		*arr;
}					t_graph;

typedef struct		s_min_heap_node
{
	int				v;
	int				dist;
}					t_min_heap_node;

typedef struct		s_min_heap
{
	int				size;
	int				capacity;
	int				*pos;
	t_min_heap_node	**arr;
}					t_min_heap;

void				ft_push_path(t_graph *graph, int *path, int j,\
		t_list_s **rooms);
char				**ft_list_s_to_char_dob(t_list_s *list);
void				ft_print_ants(int n, t_list_s *path);
void				ft_free_graph(t_graph *graph);
t_list_s			*ft_get_map(void);
char				ft_valid_map(t_list_s *map);
char				ft_valid_size(t_list_s *map);
void				ft_free_char_doble(char **str);
char				ft_valid_room(t_list_s *rooms, char *new_room);
void				ft_free_list_s(t_list_s *list);
char				ft_valid_link(char *link, t_list_s *rooms);
int					ft_room_weight(int src_x, int src_y, int dest_x,\
		int dest_y);
int					ft_sqrt(int n);
int					ft_graph_index_extract(t_graph *graph, char *src);
char				ft_valid_solution(t_graph *graph, t_list_s *map);
char				ft_dijkstra(t_graph *graph, int src, int dest);
void				ft_solve_map(t_list_s *map, char *start_name,\
		char *end_name);
void				ft_print_map(t_list_s *map);
int					*ft_dijkstra_path(t_graph *graph, int src);
void				ft_free_t_room(t_room *room);
void				ft_print_arr(int *dist, int n, t_graph *graph, int *path);
char				ft_is_in_min_heap(t_min_heap *min_heap, int v);
void				ft_decrease_key(t_min_heap *min_heap, int v, int dist);
t_min_heap_node		*ft_extract_min_heap(t_min_heap *min_heap);
char				ft_is_heap_empty(t_min_heap *min_heap);
void				ft_swap_min_heap_node(t_min_heap_node **a,\
		t_min_heap_node **b);
t_min_heap_node		*ft_new_min_heap_node(int v, int dist);
void				ft_min_heapify(t_min_heap *min_heap, int idx);
void				ft_print_graph(t_graph *graph);
t_min_heap			*ft_create_min_heap(int capacity);
int					ft_number_of_ants(t_list_s **map);
t_list_s			*ft_comments(t_list_s **map);
char				ft_is_room(char *str);
char				*ft_start(t_list_s **map);
char				*ft_end(t_list_s **map);
t_list_s			*ft_the_rooms(t_list_s **map);
char				ft_is_link(char *str);
t_list_s			*ft_the_links(t_list_s **maps, t_list_s *rooms);
t_graph				*ft_graph_create_adj(t_list_s *rooms, int n);
t_room				*ft_new_room(t_list_s *the_rooms, char *src,\
		t_room_list room_list, int i);
t_graph				*ft_graph_add_edge(t_graph *graph, t_list_s *the_rooms,\
		char *src, char *dest);
t_graph				*ft_graph_parser(t_list_s *rooms, t_list_s *links);

#endif

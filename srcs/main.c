/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 02:32:59 by eurodrig          #+#    #+#             */
/*   Updated: 2017/06/25 03:22:12 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

void ft_free_char_doble(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (j < i)
	{
		ft_memdel((void **)&str[i]);
		j++;
	}
	ft_memdel((void **)&str);
}

void ft_free_list_s(t_list_s *list)
{
	t_list_s *tmp;

	tmp = 0;
	while (list)
	{
		tmp = list->next;
		ft_memdel((void **)&list);
		list = tmp;
	}
}




char *ft_start(t_list_s **map)
{
	t_list_s *tmp;
	char **start_name;

	tmp = 0;
	tmp = *map;
	while (tmp && ft_strcmp(tmp->data, "##start"))
		tmp = tmp->next;
	while (tmp && !ft_strncmp(tmp->data, "#", 1) && !ft_is_room(tmp->data))
		tmp = tmp->next;
	if (tmp && ft_is_room(tmp->data))
	{
		start_name = ft_strsplit(tmp->data, ' ');
		return (start_name[0]);
	}
	return (0);
}

char *ft_end(t_list_s **map)
{
	t_list_s *tmp;

	tmp = 0;
	tmp = *map;
	while (tmp && ft_strcmp(tmp->data, "##end"))
		tmp = tmp->next;
	while (tmp && !ft_strncmp(tmp->data, "#", 1) && !ft_is_room(tmp->data))
		tmp = tmp->next;
	if (tmp && ft_is_room(tmp->data))
		return (tmp->data);
	return (0);
}




// char ft_valid_map(t_list_s *maps, t_list_s *comments, t_list_s *rooms, t_list_s *links)
// {
// 	int lines;
// 	int n_comments;
// 	int n_rooms;
// 	int n_links;
//
// 	lines = ft_list_size_s(maps);
// 	n_comments = ft_list_size_s(comments);
// 	n_rooms = ft_list_size_s(rooms);
// 	n_links = ft_list_size_s(links);
// 	if ((n_comments + n_rooms + n_links + 1 != lines) || n_rooms == 0)
// 		return (0);
// 	return (1);
// }

t_graph *ft_graph_create_adj(t_list_s *rooms, int n)
{
	t_graph *graph;
	int i;
	char **room;

	i = 0;
	graph = 0;
	if (!(graph = (t_graph *)malloc(sizeof(t_graph))))
		return (0);
	if (!(graph->arr = (t_room_list *)malloc(sizeof(t_room_list) * n)))
		return (0);
	while (i < n)
	{
		room = ft_strsplit(rooms->data, ' ');
		graph->arr[i].name = ft_strdup(room[0]);
		graph->arr[i].head = 0;
		graph->arr[i].x = ft_atoi(room[1]);
		graph->arr[i].y = ft_atoi(room[2]);
		i++;
		rooms = rooms->next;
	}
	graph->n = n;
	return (graph);
}

int ft_sqrt(int n)
{
	int i;

	i = 1;
	while ((i * i) < n)
		i++;
	return (i);
}

int ft_room_weight(int src_x, int src_y, int dest_x, int dest_y)
{
	int x;
	int y;
	int c;

	x = dest_x - src_x;
	y = dest_y - src_y;
	c = (x * x) + (y * y);
	return (ft_sqrt(c));
}

t_room *ft_new_room(t_list_s *the_rooms, char *src, t_room_list room_list, int i)
{
	t_room *room;
	char **info;

	room = 0;
	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (0);
	while (the_rooms)
	{
		info = ft_strsplit(the_rooms->data, ' ');
		if (!ft_strcmp(info[0], src))
		{
			room->name = ft_strdup(info[0]);
			room->dest = i;
			room->x = ft_atoi(info[1]);
			room->y = ft_atoi(info[2]);
			room->next = 0;
			room->weight = ft_room_weight(room_list.x, room_list.y, room->x, room->y);
			return (room);
		}
		the_rooms = the_rooms->next;
	}
	return (0);
}

int ft_graph_index_extract(t_graph *graph, char *src)
{
	int i;

	i = 0;
	while (i < graph->n)
	{
		if (!ft_strcmp(graph->arr[i].name, src))
			break ;
		i++;
	}
	return (i);
}

t_graph *ft_graph_add_edge(t_graph *graph, t_list_s *the_rooms, char *src, char *dest)
{
	t_room *room;
	int i;

	i = 0;
	room = 0;
	while (i < graph->n)
	{
		if (!ft_strcmp(graph->arr[i].name, src))
		{
			room = ft_new_room(the_rooms, dest, graph->arr[i], ft_graph_index_extract(graph, dest));
			room->next = graph->arr[i].head;
			graph->arr[i].head = room;
			return (graph);
		}
		i++;
	}
	return (graph);
}

t_graph *ft_graph_parser(t_list_s *rooms, t_list_s *links)
{
	t_graph *graph;
	char **l_rooms;

	graph = 0;
	graph = ft_graph_create_adj(rooms, ft_list_size_s(rooms));
	while (links)
	{
		l_rooms = ft_strsplit(links->data, '-');
		graph = ft_graph_add_edge(graph, rooms, l_rooms[0], l_rooms[1]);
		links = links->next;
	}
	return (graph);
}

void ft_print_graph(t_graph *graph)
{
	int i;
	t_room *room;

	i = 0;
	room = 0;
	while (i < graph->n)
	{
		room = graph->arr[i].head;
		printf("\nAd list of vertex %s\n head, x: %d, y: %d, dest: %d", graph->arr[i].name, graph->arr[i].x, graph->arr[i].y, i);
		while (room)
		{
			printf("-> %s, x: %d, y: %d, weight: %d, dest: %d", room->name, room->x, room->y, room->weight, room->dest);
			room = room->next;
		}
		i++;
	}
}

t_min_heap_node *ft_new_min_heap_node(int v, int dist)
{
	t_min_heap_node *node;

	if (!(node = (t_min_heap_node *)malloc(sizeof(t_min_heap_node))))
		return (0);
	node->v = v;
	node->dist = dist;
	return (node);
}

t_min_heap *ft_create_min_heap(int capacity)
{
	t_min_heap *min_heap;

	if (!(min_heap = (t_min_heap *)malloc(sizeof(t_min_heap))))
		return (0);
	min_heap->pos = (int *)malloc(sizeof(t_min_heap));
	min_heap->size = 0;
	min_heap->capacity = capacity;
	min_heap->arr = (t_min_heap_node **)malloc(sizeof(t_min_heap_node *) * capacity);
	return (min_heap);
}

void ft_swap_min_heap_node(t_min_heap_node **a, t_min_heap_node **b)
{
	t_min_heap_node *t;

	t = *a;
	*a = *b;
	*b = t;
}

void ft_min_heapify(t_min_heap *min_heap, int idx)
{
	int smallest;
	int left;
	int right;
	t_min_heap_node *smallest_node;
	t_min_heap_node *idx_node;

	left = 2 * idx + 1;
	right = 2 * idx + 2;
	smallest_node = 0;
	idx_node = 0;
	smallest = idx;
	if (left < min_heap->size && min_heap->arr[left]->dist < min_heap->arr[smallest]->dist)
		smallest = left;
	if (right < min_heap->size && min_heap->arr[right]->dist < min_heap->arr[smallest]->dist)
		smallest = right;
	if (smallest != idx)
	{
		smallest_node = min_heap->arr[smallest];
		idx_node = min_heap->arr[idx];
		min_heap->pos[smallest_node->v] = idx;
		min_heap->pos[idx_node->v] = smallest;
		ft_swap_min_heap_node(&min_heap->arr[smallest], &min_heap->arr[idx]);
		ft_min_heapify(min_heap, smallest);
	}
}

int ft_is_heap_empty(t_min_heap *min_heap)
{
	return ((min_heap->size == 0) ? 1 : 0);
}


t_min_heap_node *ft_extract_min_heap(t_min_heap *min_heap)
{
	t_min_heap_node *root;
	t_min_heap_node *last_node;

	if (ft_is_heap_empty(min_heap))
		return (0);
	root = 0;
	last_node = 0;
	root = min_heap->arr[0];
	last_node = min_heap->arr[min_heap->size - 1];
	min_heap->arr[0] = last_node;
	min_heap->pos[root->v] = min_heap->size - 1;
	min_heap->pos[last_node->v] = 0;
	--min_heap->size;
	ft_min_heapify(min_heap, 0);
	return (root);
}

void ft_decrease_key(t_min_heap *min_heap, int v, int dist)
{
	int i;

	i = min_heap->pos[v];
	min_heap->arr[i]->dist = dist;
	while (i && min_heap->arr[i]->dist < min_heap->arr[(i - 1) / 2]->dist)
	{
		min_heap->pos[min_heap->arr[i]->v] = (i - 1) / 2;
		min_heap->pos[min_heap->arr[(i - 1) / 2]->v] = i;
		ft_swap_min_heap_node(&min_heap->arr[i], &min_heap->arr[(i - 1)]);
		i = (i - 1) / 2;
	}
}

char ft_is_in_min_heap(t_min_heap *min_heap, int v)
{
	if (min_heap->pos[v] < min_heap->size)
		return (1);
	return (0);
}

void ft_print_arr(int *dist, int n, t_graph *graph)
{
	int i;

	i = 0;
	printf("name\t\tvertex\t\tdistance from source\n");
	while (i < n)
	{
		printf("%s\t\t %d \t \t %d\n", graph->arr[i].name, i, dist[i]);
		i++;
	}
}

void ft_dijkstra(t_graph *graph, int src)
{
	int v;
	int n;
	int u;
	int *dist;
	t_min_heap *min_heap;
	t_min_heap_node *min_heap_node;
	t_room *p_crawl;

	min_heap_node = 0;
	p_crawl = 0;
	min_heap = 0;
	v = graph->n;
	dist = (int *)malloc(sizeof(int) * v);
	min_heap = ft_create_min_heap(v);
	n = 0;
	while (n < v)
	{
		dist[n] = INT_MAX;
		min_heap->arr[n] = ft_new_min_heap_node(n, dist[n]);
		min_heap->pos[n] = n;
		n++;
	}
	min_heap->arr[src] = ft_new_min_heap_node(src, dist[src]);
	min_heap->pos[src] = src;
	dist[src] = 0;
	ft_decrease_key(min_heap, src, dist[src]);
	min_heap->size = v;
	while (!ft_is_heap_empty(min_heap))
	{
		min_heap_node = ft_extract_min_heap(min_heap);
		u = min_heap_node->v;
		p_crawl = graph->arr[u].head;
		while (p_crawl)
		{
			n = p_crawl->dest;
			// printf("is in min heap? %d, dist[u=%d]: %d, dist[n=%d]: %d\n", ft_is_in_min_heap(min_heap, n), u, dist[u], n, dist[n]);
			if (ft_is_in_min_heap(min_heap, n) && dist[u] != INT_MAX && p_crawl->weight + dist[u] < dist[n])
			{
				dist[n] = dist[u] + p_crawl->weight;
				ft_decrease_key(min_heap, n, dist[n]);
			}
			p_crawl = p_crawl->next;
		}
	}
	ft_print_arr(dist, v, graph);
}

// void 	ft_solve_map(t_list_s *map, t_list_s *rooms, t_list_s *links)
// {
//
//
// }

int main()
{
	char *buf;
	// int ret;
	t_list_s *map;
	t_list_s *comments;
	t_list_s *rooms;
	t_list_s *links;
	t_list_s *tmp;
	t_graph *graph;

	buf = 0;
	map = 0;
	comments = 0;
	links = 0;
	rooms = 0;
	tmp = 0;
	graph = 0;
	map = ft_get_map();
	if (!ft_valid_map(map))
		return (0);
	tmp = map;
	printf("map:\n");
	while (tmp)
	{
		ft_printf("%s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\nend map\n");
	rooms = ft_the_rooms(&map);
	links = ft_the_links(&map, rooms);
	graph = ft_graph_parser(rooms, links);
	printf("\nImprimiendo el graph:\n");
	ft_print_graph(graph);
	int idx;
	char *start_name;

	printf("\nImprimiendo Dijasktra:\n");
	idx = 0;
	start_name = ft_start(&map);
	while (idx < graph->n)
	{
		if (!ft_strcmp(graph->arr[idx].name, start_name))
		{
			printf("Entro en el vertex: idx: %d, nombre: %s\n", idx, graph->arr[idx].name);
			ft_dijkstra(graph, idx);
			return (0);
		}
		idx++;
	}

	return (0);
}

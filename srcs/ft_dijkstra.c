/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dijkstra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 21:36:07 by eurodrig          #+#    #+#             */
/*   Updated: 2017/07/04 02:56:06 by eurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lem_in.h"

int		*ft_dijkstra_helper_a(int v, t_min_heap *min_heap, int src)
{
	int				*dist;
	int				n;

	dist = (int *)malloc(sizeof(int) * v);
	n = 0;
	while (n < v)
	{
		dist[n] = INT_MAX;
		min_heap->arr[n] = ft_new_min_heap_node(n, dist[n]);
		min_heap->pos[n] = n;
		n++;
	}
	ft_memdel((void **)&(min_heap->arr[src]));
	min_heap->arr[src] = ft_new_min_heap_node(src, dist[src]);
	min_heap->pos[src] = src;
	dist[src] = 0;
	ft_decrease_key(min_heap, src, dist[src]);
	min_heap->size = v;
	return (dist);
}

int		ft_int_arr_index_extract(int *arr, int len, int i)
{
	int				n;

	n = 0;
	while (n < len)
	{
		if (arr[n] == i)
			return (n);
		n++;
	}
	return (-1);
}

void	ft_dijkstra_helper_b(t_min_heap *min_heap, int *dist, t_graph *graph,\
		int *path)
{
	t_min_heap_node	*min_heap_node;
	t_room			*p_crawl;
	int				u;
	int				n;

	path[ft_int_arr_index_extract(dist, graph->n, 0)] = -1;
	while (!ft_is_heap_empty(min_heap))
	{
		min_heap_node = ft_extract_min_heap(min_heap);
		u = min_heap_node->v;
		p_crawl = graph->arr[u].head;
		while (p_crawl)
		{
			n = p_crawl->dest;
			if (ft_is_in_min_heap(min_heap, n) && dist[u] != INT_MAX &&\
					(p_crawl->weight + dist[u] < dist[n]))
			{
				dist[n] = dist[u] + p_crawl->weight;
				path[n] = u;
				ft_decrease_key(min_heap, n, dist[n]);
			}
			p_crawl = p_crawl->next;
		}
		ft_memdel((void **)&min_heap_node);
	}
}

char	ft_dijkstra(t_graph *graph, int src, int dest)
{
	int				v;
	int				*dist;
	int				*path;
	t_min_heap		*min_heap;

	min_heap = 0;
	v = graph->n;
	path = (int *)malloc(sizeof(int) * v);
	min_heap = ft_create_min_heap(v);
	dist = ft_dijkstra_helper_a(v, min_heap, src);
	ft_dijkstra_helper_b(min_heap, dist, graph, path);
	ft_memdel((void **)&(min_heap->pos));
	ft_memdel((void **)&(min_heap->arr));
	ft_memdel((void **)&(min_heap));
	if (dist[dest] != INT_MAX)
	{
		ft_memdel((void **)&dist);
		ft_memdel((void **)&path);
		return (1);
	}
	ft_memdel((void **)&dist);
	ft_memdel((void **)&path);
	return (0);
}

int		*ft_dijkstra_path(t_graph *graph, int src)
{
	int				v;
	int				*dist;
	t_min_heap		*min_heap;
	int				*path;

	min_heap = 0;
	v = graph->n;
	path = (int *)malloc(sizeof(int) * v);
	min_heap = ft_create_min_heap(v);
	dist = ft_dijkstra_helper_a(v, min_heap, src);
	ft_dijkstra_helper_b(min_heap, dist, graph, path);
	ft_memdel((void **)&(min_heap->pos));
	ft_memdel((void **)&(min_heap->arr));
	ft_memdel((void **)&(min_heap));
	ft_memdel((void **)&dist);
	return (path);
}

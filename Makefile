# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eurodrig <eurodrig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 17:06:20 by eurodrig          #+#    #+#              #
#    Updated: 2017/06/26 18:49:19 by eurodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LINAME = lem_in

CFLAG = -Wall -Werror -Wextra

RM = /bin/rm -rfv

C = ./srcs/

LI = $(C)main.c

L = ./includes/src/

P = ./includes/src/


LI += $(C)ft_get_map.c
LI += $(C)ft_valid_map.c
LI += $(C)ft_valid_size.c
LI += $(C)ft_number_of_ants.c
LI += $(C)ft_the_rooms.c
LI += $(C)ft_is_room.c
LI += $(C)ft_valid_room.c
LI += $(C)ft_the_links.c
LI += $(C)ft_is_link.c
LI += $(C)ft_valid_link.c
LI += $(C)ft_valid_solution.c
LI += $(C)ft_comments.c
LI += $(C)ft_graph_parser.c
LI += $(C)ft_graph_create_adj.c
LI += $(C)ft_graph_add_edge.c
LI += $(C)ft_new_room.c
LI += $(C)ft_room_weight.c
LI += $(C)ft_sqrt.c
LI += $(C)ft_free_char_doble.c
LI += $(C)ft_free_list_s.c
LI += $(C)ft_start.c
LI += $(C)ft_end.c
LI += $(C)ft_graph_index_extract.c
LI += $(C)ft_dijkstra.c
LI += $(C)ft_create_min_heap.c
LI += $(C)ft_new_min_heap_node.c
LI += $(C)ft_decrease_key.c
LI += $(C)ft_swap_min_heap_node.c
LI += $(C)ft_is_heap_empty.c
LI += $(C)ft_min_heapify.c
LI += $(C)ft_is_in_min_heap.c
LI += $(C)ft_extract_min_heap.c
LI += $(C)ft_solve_map.c
LI += $(C)ft_print_map.c

LF = $(L)btree_apply_infix.c
LF += $(L)btree_apply_prefix.c
LF += $(L)btree_apply_suffix.c
LF += $(L)btree_create_node.c
LF += $(L)btree_delete.c
LF += $(L)btree_free_node.c
LF += $(L)btree_insert_data.c
LF += $(L)btree_insert.c
LF += $(L)btree_level_count.c
LF += $(L)btree_max.c
LF += $(L)btree_min.c
LF += $(L)btree_search_tree_item.c
LF += $(L)ft_atoi.c
LF += $(L)ft_bzero.c
LF += $(L)ft_create_elem.c
LF += $(L)ft_intcmp.c
LF += $(L)ft_isalnum.c
LF += $(L)ft_isalpha.c
LF += $(L)ft_isascii.c
LF += $(L)ft_isdigit.c
LF += $(L)ft_isprint.c
LF += $(L)ft_itoa.c
LF += $(L)ft_list_at.c
LF += $(L)ft_list_clear.c
LF += $(L)ft_list_empty.c
LF += $(L)ft_list_find.c
LF += $(L)ft_list_foreach_if.c
LF += $(L)ft_list_foreach.c
LF += $(L)ft_list_last.c
LF += $(L)ft_list_pop_back.c
LF += $(L)ft_list_pop_front.c
LF += $(L)ft_list_push_back.c
LF += $(L)ft_list_push_front.c
LF += $(L)ft_list_remove_if.c
LF += $(L)ft_list_reverse.c
LF += $(L)ft_list_size.c
LF += $(L)ft_lstadd.c
LF += $(L)ft_lstdel.c
LF += $(L)ft_lstdelone.c
LF += $(L)ft_lstiter.c
LF += $(L)ft_lstlen.c
LF += $(L)ft_lstmap.c
LF += $(L)ft_lstnew.c
LF += $(L)ft_lstniter.c
LF += $(L)ft_lstprint_i.c
LF += $(L)ft_lstprint_s.c
LF += $(L)ft_memalloc.c
LF += $(L)ft_memccpy.c
LF += $(L)ft_memchr.c
LF += $(L)ft_memcmp.c
LF += $(L)ft_memcpy.c
LF += $(L)ft_memdel.c
LF += $(L)ft_memmove.c
LF += $(L)ft_memset.c
LF += $(L)ft_putchar_fd.c
LF += $(L)ft_putchar.c
LF += $(L)ft_putendl_fd.c
LF += $(L)ft_putendl.c
LF += $(L)ft_putnbr_fd.c
LF += $(L)ft_putnbr.c
LF += $(L)ft_putstr_fd.c
LF += $(L)ft_putstr.c
LF += $(L)ft_pwr.c
LF += $(L)ft_str_includes.c
LF += $(L)ft_strcat.c
LF += $(L)ft_strchr.c
LF += $(L)ft_strcmp.c
LF += $(L)ft_strcpy.c
LF += $(L)ft_strdel.c
LF += $(L)ft_strdup.c
LF += $(L)ft_strequ.c
LF += $(L)ft_striter.c
LF += $(L)ft_striteri.c
LF += $(L)ft_strjoin.c
LF += $(L)ft_strlcat.c
LF += $(L)ft_strlen.c
LF += $(L)ft_strmap.c
LF += $(L)ft_strmapi.c
LF += $(L)ft_strncat.c
LF += $(L)ft_strncmp.c
LF += $(L)ft_strncpy.c
LF += $(L)ft_strnequ.c
LF += $(L)ft_strnew.c
LF += $(L)ft_strnstr.c
LF += $(L)ft_strrchr.c
LF += $(L)ft_strsplit.c
LF += $(L)ft_strstr.c
LF += $(L)ft_strsub.c
LF += $(L)ft_strtrim.c
LF += $(L)ft_tolower.c
LF += $(L)ft_toupper.c
LF += $(L)ft_max_number.c
LF += $(L)ft_lst_new.c
LF += $(L)ft_lst_push_back.c
LF += $(L)ft_lst_len.c
LF += $(L)ft_lst_includes.c
LF += $(L)ft_lst_to_s.c
LF += $(L)get_next_line.c
LF += $(L)ft_list_includes.c
LF += $(L)ft_itoa_base_n.c

PF = $(P)ft_print_blank.c
PF += $(P)ft_printf_c.c
PF += $(P)ft_printf_flags.c
PF += $(P)ft_printf_length.c
PF += $(P)ft_printf_params_init.c
PF += $(P)ft_printf_precision.c
PF += $(P)ft_printf_s.c
PF += $(P)ft_printf_str_trim.c
PF += $(P)ft_printf_width.c
PF += $(P)ft_printf.c
PF += $(P)ft_putchar_n_bytes.c
PF += $(P)ft_printf_str_contains.c
PF += $(P)ft_wstrlen.c
PF += $(P)ft_itoa_base.c
PF += $(P)ft_printf_d.c
PF += $(P)ft_print_sign.c
PF += $(P)ft_print_zero.c
PF += $(P)ft_printf_d_helper.c
PF += $(P)ft_printf_u.c
PF += $(P)ft_printf_u_helper.c
PF += $(P)ft_printf_o.c
PF += $(P)ft_printf_o_helper.c
PF += $(P)ft_printf_x.c
PF += $(P)ft_printf_x_helper.c
PF += $(P)ft_printf_lx.c
PF += $(P)ft_printf_lx_helper.c
PF += $(P)ft_printf_percent.c
PF += $(P)ft_printf_symbol.c
PF += $(P)ft_printf_n_helper.c
PF += $(P)ft_printf_n.c
PF += $(P)ft_multiple_memdel.c
PF += $(P)ft_printf_s_helper.c

OF = btree_apply_infix.o
OF += btree_apply_prefix.o
OF += btree_apply_suffix.o
OF += btree_create_node.o
OF += btree_delete.o
OF += btree_free_node.o
OF += btree_insert_data.o
OF += btree_insert.o
OF += btree_level_count.o
OF += btree_max.o
OF += btree_min.o
OF += btree_search_tree_item.o
OF += ft_atoi.o
OF += ft_bzero.o
OF += ft_create_elem.o
OF += ft_intcmp.o
OF += ft_isalnum.o
OF += ft_isalpha.o
OF += ft_isascii.o
OF += ft_isdigit.o
OF += ft_isprint.o
OF += ft_itoa.o
OF += ft_list_at.o
OF += ft_list_clear.o
OF += ft_list_empty.o
OF += ft_list_find.o
OF += ft_list_foreach_if.o
OF += ft_list_foreach.o
OF += ft_list_last.o
OF += ft_list_pop_back.o
OF += ft_list_pop_front.o
OF += ft_list_push_back.o
OF += ft_list_push_front.o
OF += ft_list_remove_if.o
OF += ft_list_reverse.o
OF += ft_list_size.o
OF += ft_lstadd.o
OF += ft_lstdel.o
OF += ft_lstdelone.o
OF += ft_lstiter.o
OF += ft_lstlen.o
OF += ft_lstmap.o
OF += ft_lstnew.o
OF += ft_lstniter.o
OF += ft_lstprint_i.o
OF += ft_lstprint_s.o
OF += ft_memalloc.o
OF += ft_memccpy.o
OF += ft_memchr.o
OF += ft_memcmp.o
OF += ft_memcpy.o
OF += ft_memdel.o
OF += ft_memmove.o
OF += ft_memset.o
OF += ft_putchar_fd.o
OF += ft_putchar.o
OF += ft_putendl_fd.o
OF += ft_putendl.o
OF += ft_putnbr_fd.o
OF += ft_putnbr.o
OF += ft_putstr_fd.o
OF += ft_putstr.o
OF += ft_pwr.o
OF += ft_str_includes.o
OF += ft_strcat.o
OF += ft_strchr.o
OF += ft_strcmp.o
OF += ft_strcpy.o
OF += ft_strdel.o
OF += ft_strdup.o
OF += ft_strequ.o
OF += ft_striter.o
OF += ft_striteri.o
OF += ft_strjoin.o
OF += ft_strlcat.o
OF += ft_strlen.o
OF += ft_strmap.o
OF += ft_strmapi.o
OF += ft_strncat.o
OF += ft_strncmp.o
OF += ft_strncpy.o
OF += ft_strnequ.o
OF += ft_strnew.o
OF += ft_strnstr.o
OF += ft_strrchr.o
OF += ft_strsplit.o
OF += ft_strstr.o
OF += ft_strsub.o
OF += ft_strtrim.o
OF += ft_tolower.o
OF += ft_toupper.o

OF += ft_max_number.o
OF += ft_print_blank.o
OF += ft_printf_c.o
OF += ft_printf_flags.o
OF += ft_printf_length.o
OF += ft_printf_params_init.o
OF += ft_printf_precision.o
OF += ft_printf_s.o
OF += ft_printf_str_trim.o
OF += ft_printf_width.o
OF += ft_printf.o
OF += ft_putchar_n_bytes.o
OF += ft_printf_str_contains.o
OF += ft_wstrlen.o
OF += ft_itoa_base.o
OF += ft_printf_d.o
OF += ft_print_sign.o
OF += ft_print_zero.o
OF += ft_printf_d_helper.o
OF += ft_printf_u.o
OF += ft_printf_u_helper.o
OF += ft_printf_o.o
OF += ft_printf_o_helper.o
OF += ft_printf_x.o
OF += ft_printf_x_helper.o
OF += ft_printf_lx.o
OF += ft_printf_lx_helper.o
OF += ft_printf_percent.o
OF += ft_printf_symbol.o
OF += ft_printf_n.o
OF += ft_printf_n_helper.o
OF += ft_multiple_memdel.o
OF += ft_printf_s_helper.o
OF += ft_lst_new.o
OF += ft_lst_push_back.o
OF += ft_lst_len.o
OF += ft_lst_includes.o
OF += ft_lst_to_s.o
OF += get_next_line.o
OF += ft_list_includes.o
OF += ft_itoa_base_n.o

all: $(LINAME)

$(LINAME):
				@echo compiling...
			 	@gcc $(CFLAG) -c $(LF) $(PF) -I ./includes/
			 	@ar rc libftprintf.a $(OF)
				@ranlib libftprintf.a
				@gcc $(CFLAG) $(LI) libftprintf.a -I ./includes/ -o $(LINAME)
				@echo "$(LINAME)" ready to be used

clean:
				@$(RM) $(OF)| wc -l | tr '\n' ' ' && echo files deleted

fclean: clean
				@$(RM) $(LINAME) libftprintf.a | wc -l | tr '\n' ' ' && echo $(LINAME) libftprintf.a deleted

re: fclean all

.PHONY: clean fclean re

.PHONY: clean fclean re

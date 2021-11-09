/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vifernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:13:40 by vifernan          #+#    #+#             */
/*   Updated: 2021/11/09 16:15:54 by vifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_LIB_H
#define PUSH_SWAP_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct s_element {
	int num;
	struct s_element *next;
	struct s_element *prev;
}				t_element;

typedef struct s_list {
	t_element *first;
	t_element *last;
	int  size;
}				t_list;

#endif

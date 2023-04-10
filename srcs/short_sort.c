/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:38:11 by esali             #+#    #+#             */
/*   Updated: 2023/04/10 16:39:51 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	short_stack_sort(t_list *a, char *ab)
{
	if (((a->next->next->content) > (a->content)) && ((a->content) > (a->next->content))) {
		s(a, ab);
	}
}

void	short_sort(int len, t_list *a, char *ab)
{
	if (len == 3)
		short_stack_sort(a, ab);
}

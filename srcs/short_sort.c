/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esali <esali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:38:11 by esali             #+#    #+#             */
/*   Updated: 2023/05/19 18:42:23 by esali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list *a, char ab)
{
	if (((a->content) < (a->next->next->content)) && ((a->content) > (a->next->content)))
		s(a, ab);
	else if (((a->next->next->content) < (a->content)) && ((a->next->next->content) > (a->next->content)))
		r(a, ab);
	else if (((a->content) < (a->next->content)) && ((a->content) > (a->next->next->content)))
		rr(a, ab);
	else if (((a->next->content) < (a->content)) && ((a->next->content) > (a->next->next->content)))
	{
		r(a, ab);
		s(a, ab);
	}
	else if (((a->next->next->content) < (a->next->content)) && ((a->next->next->content) > (a->content)))
	{
		rr(a, ab);
		s(a, ab);
	}
}

// Function puts a number on the correct spot in a sorted list of numbers
void	put_in_stack(t_list **from, t_list **into, char ab)
{
	int		len;
	int		pos;
	int		i;
	t_list	*tmp;

	len = ft_lstsize(*into); //size of into
	tmp = *into;
	pos = 0;
	while (tmp) // calculates position of where number should go into
	{
		if ((*from)->content < tmp->content)
			break;
		pos++;
		tmp = tmp->next;
	}
	if ((len / 2) < pos) // if pos < (len / 2) turns list with rr and back again
	{
		pos = len - pos;
		i = pos + 1;
		while (pos--)
			rr(*into, ab);
		p(from, into, ab);
		while (i --)
			r(*into, ab);
	}
	else // if pos > (len / 2) turns list with r and back again
	{
		i = pos;
		while (pos--)
			r(*into, ab);
		p(from, into, ab);
		while(i--)
			rr(*into, ab);
	}
}

void	short_sort(int len, t_list **list)
{
	t_list	*b;

	b = NULL;
	if (len == 2)
		s(*list, 'a');
	else if (len == 3)
		sort3(*list, 'a');
	else
	{
		p(list, &b, 'b');
		if (len == 5)
			p(list, &b, 'b');
		sort3(*list, 'a');
		put_in_stack(&b, list, 'a');
		if (len == 5)
			put_in_stack(&b, list, 'a');
	}
}

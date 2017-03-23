/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:15:48 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 17:03:25 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_put_dig_in_b(int **tab_a, int **tab_b, t_st *ps)
{
	int		swap;
	size_t	i;
	int		*tab_tmp;

	if (!(*tab_a)[0])
		return (1);
	ps->a_len--;
	swap = (*tab_a)[0];
	tab_tmp = (int *)malloc(sizeof(int) * ps->a_len);
	i = -1;
	while (++i < ps->a_len)
		tab_tmp[i] = (*tab_a)[i + 1];
	free(*tab_a);
	*tab_a = tab_tmp;
	ps->b_len++;
	tab_tmp = (int *)malloc(sizeof(int) * ps->b_len);
	tab_tmp[0] = swap;
	i = 0;
	while (++i < ps->b_len)
		tab_tmp[i] = (*tab_b)[i - 1];
	free(*tab_b);
	*tab_b = tab_tmp;
	ps->move++;
//	ft_put_tabs(tab_a, tab_b, ps);
//	ps->vis ? ft_put_tabs(tab_a, tab_b, ps) : 0;
	if (!ps->sil)
		ft_printf("pb\n");
	return (1);
}

int		ft_put_dig_in_a(int **tab_a, int **tab_b, t_st *ps)
{
	int		swap;
	size_t	i;
	int		*tab_tmp;
	int		*tab_tmp2;

	if (!(*tab_b)[0])
		return (1);
	ps->b_len--;
	swap = (*tab_a)[0];
	tab_tmp = (int *)malloc(sizeof(int) * ps->b_len);
	i = -1;
	while (++i < ps->b_len)
		tab_tmp[i] = (*tab_a)[i + 1];
	free(*tab_a);
	(*tab_a) = tab_tmp;
	ps->a_len++;
	tab_tmp2 = (int *)malloc(sizeof(int) * ps->a_len);
	tab_tmp2[0] = swap;
	i = 0;
	while (++i < ps->a_len)
		tab_tmp2[i] = (*tab_b)[i - 1];
	free(*tab_b);
	(*tab_b) = tab_tmp2;
	ps->move++;
//	ps->vis ? ft_put_tabs(tab_a, tab_b, ps) : 0;
	if (!ps->sil)
		ft_printf("pa\n");
	return (1);
}

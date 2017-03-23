/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:58:48 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 15:37:35 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_put_med_b(int **tab_a, int **tab_b, t_st *ps, int size)
{
	int i;
	int res;
	int tmp;

	res = 0;
	ps->rot = 0;
	i = 0;
	tmp = ps->a_len;
	if (size <= 6)
		return (ft_sort_less_6(tab_a, tab_b, size, ps));
	while (i < size)
	{
		if (!ft_check_next_dig(tab_a, ps->med, size, 0))
			break ;
		if ((*tab_a)[0] <= ps->med && ++res)
			ft_put_dig_in_b(tab_a, tab_b, ps);
		else if (++ps->rot)
			ft_rotate(tab_a, ps->a_len, ps, 1);
		i++;
	}
	if (tmp == size)
		ps->rot = 0;
	return (res);
}

int		ft_put_if_less_3_b(int **tab_a, int **tab_b, size_t size, t_st *ps)
{
	if (size <= 3 && size > 0)
	{
		ps->car += size;
		if (size >= 2)
		{
			if ((*tab_b)[0] > (*tab_b)[1] &&
					(*tab_b)[0] > (*tab_b)[2] && size--)
				ft_put_dig_in_a(tab_b, tab_a, ps);
			if ((*tab_b)[0] < (*tab_b)[1])
				ft_swap_first(tab_b, ps, 2);
			if (size == 3 && ps->b_len > 2 && ((*tab_b)[1] < (*tab_b)[2]))
			{
				ft_rotate(tab_b, ps->b_len, ps, 2);
				ft_swap_first(tab_b, ps, 2);
				ft_rotate_rev(tab_b, ps->b_len, ps, 2);
			}
			if ((*tab_b)[0] < (*tab_b)[1])
				ft_swap_first(tab_b, ps, 2);
		}
		while (size--)
			ft_put_dig_in_a(tab_b, tab_a, ps);
		return (1);
	}
	return (0);
}

void	ft_check_b_a(int **tab_a, int **tab_b, int size, t_st *ps)
{
	int res2;

	if (!size)
		return ;
	res2 = 0;
	if (size >= 4 && ps->b_len)
	{
		ft_calc_med(*tab_b, size, ps);
		res2 = ft_put_med_a(tab_a, tab_b, ps, size);
		while (ps->rot--)
			ft_rotate_rev(tab_b, ps->b_len, ps, 2);
		ps->rot = 0; // chaeck
		while (ps->rot--)
			ft_rotate_rev(tab_b, ps->b_len, ps, 2);
		ft_check_a_b(tab_a, tab_b, res2, ps);
		ft_check_b_a(tab_a, tab_b, size - res2, ps);
	}
	if (ft_put_if_less_3_b(tab_a, tab_b, size, ps))
		return ;
	else if (size <= 0)
		return ;
}

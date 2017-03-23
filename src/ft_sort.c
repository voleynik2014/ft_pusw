/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:43:30 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 15:57:19 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_next_dig(int **tab_a, int med, int size, int fl)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (!fl && (*tab_a)[i] && (*tab_a)[i] <= med)
			return (1);
		if (fl && (*tab_a)[i] && (*tab_a)[i] > med)
			return (1);
	}
//	ft_printf("AL");
	return (0);
}

int		ft_put_med_a(int **tab_a, int **tab_b, t_st *ps, int size)
{
	int	i;
	int	res;
	int	tmp;

	ps->rot = 0;
	res = 0;
	i = 0;
	tmp = ps->b_len;
	{
		if (size <= 6)
			return (ft_sort_less_6_b(tab_b, tab_a, size, ps));
		while (i < size)
		{
			if (!ft_check_next_dig(tab_a, ps->med, size, 1))
				break ;
			if ((*tab_b)[0] >= ps->med && ++res)
				ft_put_dig_in_a(tab_b, tab_a, ps);
			else if (++ps->rot)
				ft_rotate(tab_b, ps->b_len, ps, 2);
			i++;
		}
	}
	if (tmp == size)
		ps->rot = 0;
	return (res);
}

void	ft_put_if_less_3(int **tab_a, size_t size, t_st *ps)
{
	if (size <= 3 && size > 0)
	{
		ps->car += size;
		if (size == ps->a_len)
		{
			if ((*tab_a)[0] > (*tab_a)[1])
				ft_swap_first(tab_a, ps, 1);
			if ((*tab_a)[2] < (*tab_a)[1] && (*tab_a)[2] < (*tab_a)[0])
				ft_rotate_rev(tab_a, ps->a_len, ps, 1);
		}
		if (size >= 2)
		{
			if ((*tab_a)[0] > (*tab_a)[1])
				ft_swap_first(tab_a, ps, 1);
			if (size >= 3 && ps->a_len > 2 && ((*tab_a)[1] > (*tab_a)[2]))
			{
				ft_rotate(tab_a, ps->a_len, ps, 1);
				ft_swap_first(tab_a, ps, 1);
				ft_rotate_rev(tab_a, ps->a_len, ps, 1);
			}
			if ((*tab_a)[0] > (*tab_a)[1])
				ft_swap_first(tab_a, ps, 1);
		}
	}
}

void	ft_check_a_b(int **tab_a, int **tab_b, int size, t_st *ps)
{
	int res;

	if (!size)
		return ;
	res = 0;
	if (size >= 4)
	{
		ft_calc_med(*tab_a, size, ps);
		res = ft_put_med_b(tab_a, tab_b, ps, size);
	//	ft_printf("OUT%d", size);
		while (ps->rot--)
			ft_rotate_rev(tab_a, ps->a_len, ps, 1);
		if (res && size - res >= 4)
			ft_check_a_b(tab_a, tab_b, size - res, ps);
		else
			size -= res;
	}
	ps->a_tmp_len = size;
	ps->b_tmp_len = res;
	if (size <= 3 && res <= 3 && size > 0 && res > 0)
		return (ft_check_and_put(tab_a, tab_b, ps));
	ft_put_if_less_3(tab_a, size, ps);
	if (size <= 0)
		return ;
	ft_check_b_a(tab_a, tab_b, res, ps);
}

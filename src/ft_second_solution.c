/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_second_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:53:01 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 15:38:35 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_check_and_put_single(int **tab_a, int **tab_b, t_st *ps)
{
	if ((*tab_a)[0] > (*tab_a)[1] && (*tab_b)[0] < (*tab_b)[1])
		ft_swap_both(tab_a, tab_b, ps);
	else if ((*tab_a)[0] > (*tab_a)[1])
		ft_swap_first(tab_a, ps, 1);
	else if ((*tab_b)[0] < (*tab_b)[1])
		ft_swap_first(tab_b, ps, 2);
	return (1);
}

int		ft_check_and_put_both(int **tab_a, int **tab_b, t_st *ps)
{
	if (ps->a_tmp_len >= 3 || ps->b_tmp_len >= 3)
	{
		if (ps->a_tmp_len >= 3 && ps->b_tmp_len >= 3 &&
				((*tab_a)[1] > (*tab_a)[2])
				&& ((*tab_b)[1] < (*tab_b)[2]))
		{
			ft_rotate_all(tab_a, tab_b, ps);
			ft_swap_both(tab_a, tab_b, ps);
			ft_rotate_all_rev(tab_a, tab_b, ps);
		}
		else if (ps->a_tmp_len >= 3 && ((*tab_a)[1] > (*tab_a)[2]))
		{
			ft_rotate(tab_a, ps->a_len, ps, 1);
			ft_swap_first(tab_a, ps, 1);
			ft_rotate_rev(tab_a, ps->a_len, ps, 1);
		}
		else if (ps->b_tmp_len >= 3 && ((*tab_b)[1] < (*tab_b)[2]))
		{
			ft_rotate(tab_b, ps->b_len, ps, 2);
			ft_swap_first(tab_b, ps, 2);
			ft_rotate_rev(tab_b, ps->b_len, ps, 2);
		}
	}
	return (1);
}

void	ft_check_and_put(int **tab_a, int **tab_b, t_st *ps)
{
	ps->car += ps->a_tmp_len + ps->b_tmp_len;
	ft_check_and_put_single(tab_a, tab_b, ps);
	ft_check_and_put_both(tab_a, tab_b, ps);
	ft_check_and_put_single(tab_a, tab_b, ps);
	while (ps->b_tmp_len--)
		ft_put_dig_in_a(tab_b, tab_a, ps);
	return ;
}

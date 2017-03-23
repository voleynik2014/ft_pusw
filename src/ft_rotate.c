/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:51:19 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 16:07:10 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_rotate(int **tab, size_t size, t_st *ps, int flag)
{
	int		swap;
	size_t	i;

	if ((*tab)[0])
	{
		i = 0;
		swap = (*tab)[0];
		while (++i < size)
			(*tab)[i - 1] = (*tab)[i];
		(*tab)[i - 1] = swap;
		ps->move++;
		if (flag == 1)
			ft_printf("ra\n");
		else if (flag == 2)
			ft_printf("rb\n");
	}
	return (1);
}

int		ft_rotate_all(int **tab_a, int **tab_b, t_st *ps)
{
	ft_rotate(tab_a, ps->a_len, ps, 0);
	ft_rotate(tab_b, ps->b_len, ps, 0);
	ps->move--;
	if (!ps->sil)
		ft_printf("rr\n");
	return (1);
}

int		ft_rotate_rev(int **tab, int size, t_st *ps, int flag)
{
	int		swap;
	int		i;

	if ((*tab)[0])
	{
		i = size;
		swap = (*tab)[size - 1];
		while (--i > 0)
			(*tab)[i] = (*tab)[i - 1];
		(*tab)[0] = swap;
		ps->move++;
		if (flag == 1)
			ft_printf("rra\n");
		else if (flag == 2)
			ft_printf("rrb\n");
	}
	return (1);
}

int		ft_rotate_all_rev(int **tab_a, int **tab_b, t_st *ps)
{
	ft_rotate_rev(tab_a, ps->a_len, ps, 0);
	ft_rotate_rev(tab_b, ps->b_len, ps, 0);
	ps->move--;
	if (!ps->sil)
		ft_printf("rrr\n");
	return (1);
}

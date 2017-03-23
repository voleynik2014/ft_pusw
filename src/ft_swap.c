/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:12:02 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 16:45:23 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_swap_first(int **tab, t_st *ps, int flag)
{
	int	swap;

	if ((*tab)[1])
	{
		swap = (*tab)[0];
		(*tab)[0] = (*tab)[1];
		(*tab)[1] = swap;
		ps->move++;
		if (flag == 1)
			ft_printf("sa\n");
		else if (flag == 2)
			ft_printf("sb\n");
	}
//	ps->vis ? ft_put_tabs(tab_a, tab_b, ps) : 0;
	return (1);
}

int		ft_swap_both(int **tab_a, int **tab_b, t_st *ps)
{
	ft_swap_first(tab_a, ps, 0);
	ft_swap_first(tab_b, ps, 0);
	ps->move--;
	if ( !ps->sil)
		ft_printf("ss\n");
	return (1);
}

int		ft_count_str(char **src, int *argc)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	(*argc) = i;
	return (1);
}

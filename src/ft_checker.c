/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:50:59 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 16:31:53 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checker(char *str, int **tab_a, int **tab_b, t_st *ps)
{
	ps->sil = 1;
	if (ft_strequ(str, "sa"))
		ft_swap_first(tab_a, ps, 0);
	else if (ft_strequ(str, "sb"))
		ft_swap_first(tab_b, ps, 0);
	else if (ft_strequ(str, "ss"))
		ft_swap_both(tab_a, tab_b, ps);
	else if (ft_strequ(str, "pb"))
		ft_put_dig_in_b(tab_a, tab_b, ps);
	else if (ft_strequ(str, "pa"))
		ft_put_dig_in_a(tab_a, tab_b, ps);
	else if (ft_strequ(str, "ra"))
		ft_rotate(tab_a, ps->a_len, ps, 0);
	else if (ft_strequ(str, "rb"))
		ft_rotate(tab_b, ps->b_len, ps, 0);
	else if (ft_strequ(str, "rr"))
		ft_rotate_all(tab_a, tab_b, ps);
	else if (ft_strequ(str, "rra"))
		ft_rotate_rev(tab_a, ps->a_len, ps, 0);
	else if (ft_strequ(str, "rrb"))
		ft_rotate_rev(tab_b, ps->b_len, ps, 0);
	else if (ft_strequ(str, "rrr"))
		ft_rotate_all_rev(tab_a, tab_b, ps);
	else
		return (ft_printf("error\n"));
	return (0);
}

int		main(int argc, char **argv)
{
	char	*tmp;
	int		*tab_a;
	int		*tab_b;
	t_st	ps;

	if (argc <= 2)
		return (0);
	ft_bzero(&ps, sizeof(t_st));
	ps.a_len = (size_t)argc - 1;
	tab_a = ft_create_tab(argc - 1, argv, &ps);
	tab_b = ft_create_tab(argc - 1, 0, &ps);
	if (!ft_check_argv(argv, argc, &ps))
		return (0);
	if (ft_check_sort(&tab_a, argc - 1))
		return (0);
	while (get_next_line(0, &tmp))
		if (ft_checker(tmp, &tab_a, &tab_b, &ps))
			return (0);
	if (ft_check_sort(&tab_a, argc - 1) && ps.b_len == 0)
		ft_printf("OK");
	else
		ft_printf("KO");
	free(tab_b);
	free(tab_a);
	return (0);
}

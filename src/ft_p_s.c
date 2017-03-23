/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 12:10:44 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/21 17:53:05 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_put_tabs(int **tab_a, int **tab_b, t_st *ps)
{
	size_t	i;

	i = 0;
	printf("moves: %zu\n", ps->move);
	while (i < ps->a_len || i < ps->b_len)
	{
		if (i < ps->a_len)
		{
			if (i < ps->a_len && ps->col)
				printf("A - \x1b[32m%d\x1b[0m\t", (*tab_a)[i]);
			else
				printf("A - %d\t", (*tab_a)[i]);
		}
		else
			printf("\t");
		if (i < ps->b_len)
			printf("B - %d\n", (*tab_b)[i]);
		else
			printf("\n");
		i++;
	}
}

char	**ft_del_str(char **src, int fl)
{
	int		i;
	char	**dup;

	i = 0;
	while (src[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * i + 1);
	i = -1;
	while (src[++i + fl])
		if (src[i + fl])
			dup[i] = ft_strdup(src[i + fl]);
	dup[i] = NULL;
	return (dup);
}

char	**ft_bonus(char **argv, int *argc, t_st *ps)
{
	ps->i = 1;
	ft_count_str(argv, argc);
	if ((ft_strequ(argv[ps->i], "-vc") || ft_strequ(argv[ps->i], "-cv")) &&
			++ps->col && ++ps->vis && --(*argc))// && ++ps->i)
		return (ft_del_str(argv, 1));
	else if (ft_strequ(argv[ps->i], "-c") && ++ps->col && --(*argc))
		return (ft_del_str(argv, 1));
	else if (ft_strequ(argv[ps->i], "-v") && ++ps->vis && --(*argc))
		return (ft_del_str(argv, 1));
	return (ft_del_str(argv, 0));
}

void	ft_push_swap(int argc, char **argv)
{
	int		*tab_a;
	int		*tab_b;
	t_st	ps;
	char	**argv1;

	ft_bzero(&ps, sizeof(t_st));
	argv1 = ft_bonus(argv, &argc, &ps);
	if (!ft_check_argv(argv1, argc, &ps))
		return ;
	tab_a = ft_create_tab(argc - 1, argv1, &ps);
	tab_b = ft_create_tab(argc - 1, 0, &ps);
	int i = -1;
	while (++i < argc)
		free(argv1[i]);
	free(argv1);
	ps.a_len = (size_t)argc - 1;
	if (ft_check_sort(&tab_a, argc - 1))
		return ;
	ft_check_a_b(&tab_a, &tab_b, argc - 1, &ps);
	if (ps.vis)
		ft_put_tabs(&tab_a, &tab_b, &ps);
	free(tab_a);
	free(tab_b);
}

int		main(int argc, char **argv)
{
	ft_push_swap(argc, argv);
//	sleep(999);
	return (1);
}

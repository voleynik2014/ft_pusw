
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_st
{
	size_t		a_len;
	size_t		b_len;
	size_t		move;
	int			flag;
	int			rot;
	size_t			st;
	size_t			en;
	int			car;
	int			med;
	size_t		a_tmp_len;
	size_t		b_tmp_len;
	int			vis;
	int			col;
	int			sil;
	int			i;
}				t_st;

int		main(int argc, char **argv);
void	ft_put_tabs(int **tab_a, int **tab_b, t_st *ps);

void	ft_check_b_a(int **tab_a, int **tab_b, int size, t_st *ps);
void	ft_check_a_b(int **tab_a, int **tab_b, int size, t_st *ps);
int		ft_put_med_a(int **tab_a, int **tab_b, t_st *ps, int size);
int		ft_put_med_b(int **tab_a, int **tab_b, t_st *ps, int size);

int     ft_check_argv(char **src, int argc, t_st *ps);
int     ft_check_next(int **tab_a, int med, int size, int fl);
int		ft_check_sort(int **tab,int size);
int		*ft_create_tab(int argc, char **argv, t_st *ps);
void	ft_calc_med(int *tab, int size, t_st *ps);
int		ft_intchr(int **tab_a, int med, t_st *ps, int *num);
int     ft_check_next_dig(int **tab_a, int med, int  size, int fl);

int     ft_put_dig_in_a(int **tab_a, int **tab_b, t_st *ps);
int     ft_put_dig_in_b(int **tab_a, int **tab_b, t_st *ps);

int     ft_minint(int **tab_a, int med, t_st *ps);
int     ft_maxint(int **tab_a, int med, t_st *ps);
int     ft_revminint(int **tab_a, int med, t_st *ps);
int     ft_revmaxint(int **tab_a, int med, t_st *ps);

int     ft_rotate_one(int i, int **tab_a, int **tab_b,t_st *ps, int point);
int     ft_rotate_two(int i, int **tab_a, int **tab_b, t_st *ps, int point);

void	ft_check_and_put(int **tab_a, int **tab_b, t_st *ps);
int     ft_check_and_put_single(int **tab_a, int **tab_b, t_st *ps);
int     ft_check_and_put_both(int **tab_a, int **tab_b, t_st *ps);

int     ft_sort_less_6(int **tab_a, int **tab_b, size_t size, t_st *ps);
int     ft_sort_less_6_b(int **tab_a, int **tab_b, int size, t_st *ps);
int     ft_put_dig_in_a(int **tab_a, int **tab_b, t_st *ps);
int     ft_put_dig_in_b(int **tab_a, int **tab_b, t_st *ps);

int     ft_rotate(int **tab, size_t size, t_st *ps, int flag);
int		ft_rotate_all(int **tab_a, int **tab_b, t_st *ps);
int     ft_rotate_rev(int **tab, int size,t_st *ps, int flag);
int     ft_rotate_all_rev(int **tab_a, int **tab_b, t_st *ps);

int     ft_swap_first(int **tab, t_st *ps, int flag);
int     ft_swap_both(int **tab_a, int **tab_b, t_st *ps);
int     ft_count_str(char **src, int *argc);

int     ft_dosome_oneway(int **tab_a, int **tab_b, int i, t_st *ps);
int     ft_dosome_secondway(int **tab_a, int **tab_b, int i, t_st *ps);
int     ft_oneway(int **tab_a, int med, t_st *ps, int *point);
int     ft_twoway(int **tab_a, int med, t_st *ps, int *point);

void    ft_cheker(char *str, int **tab_a, int **tab_b, t_st *ps);
#endif

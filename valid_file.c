/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:06:41 by marnaud           #+#    #+#             */
/*   Updated: 2016/11/30 12:56:30 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		test_touch(t_piece test, int n, int n2, int *nb_touch)
{
	if (test.cd[n].x == test.cd[n2].x && test.cd[n].y == test.cd[n2].y + 1)
		(*nb_touch)++;
	if (test.cd[n].x == test.cd[n2].x && test.cd[n].y == test.cd[n2].y - 1)
		(*nb_touch)++;
	if (test.cd[n].y == test.cd[n2].y && test.cd[n].x == test.cd[n2].x + 1)
		(*nb_touch)++;
	if (test.cd[n].y == test.cd[n2].y && test.cd[n].x == test.cd[n2].x - 1)
		(*nb_touch)++;
}

static int		valid_piece(t_piece test)
{
	int		nb_touch;
	int		n;
	int		n2;

	n = 0;
	nb_touch = 0;
	while (n < 4)
	{
		n2 = 0;
		while(n2 < 4)
		{
			if (n2 == n)
				n2++;
			test_touch(test, n, n2, &nb_touch);
			n2++;
		}
		n++;
	}
	if (nb_touch < 6)
		return (1);
	return (0);
}

static void		initialisation(t_point *cursor, int *n, int *nb_c, int *nb_p)
{
	*n = 0;
	*nb_c = 0;
	(*cursor).x = 1;
	(*cursor).y = 1;
	*nb_p = 0;
}

static void		condition_n(t_point *cursor, t_piece *test, int *nb_c, int n)
{
	if (n == 1)
	{
		(*cursor).y += 1;
		(*cursor).x = 0;
	}
	if (n == 2)
	{
		(*test).cd[*nb_c] = *cursor;
		(*nb_c) += 1;
	}
}

static void		condition_hard(t_point *cursor, int *nb_c, int *nb_p)
{
	(*cursor).y = 0;
	*nb_c = 0;
	(*nb_p) += 1;
}

static int		test_str(char *str, int n, t_point *cursor, int i)
{
	if (i == 1)
	{
		(*cursor).x += 1;
		return (n + 1);
	}
	if (str[n] != '.' && str[n] != '#' && str[n] != '\n')
		return (1);
	if ((str[n] == '\n' && str[n + 1] == '\n' && str[n + 2] != '\n' && str[n + 2] != '\0')
		|| (str[n] == '\n' && str[n + 1] == '\0')) 
		return (3);
	if (str[n] == '\n' && (*cursor).x != 5 && str[n - 1] != '\n')
		return (2);
	return (0);
}

int			valid_file(char *str)
{
	t_point		cursor;
	t_piece		test;
	int			n;
	int 		nb_c;
	int			nb_p;

	initialisation(&cursor, &n, &nb_c, &nb_p);
	while (str[n] != '\0')
	{
		if (str[n] == '#')
			condition_n(&cursor, &test, &nb_c, 2);
		if (test_str(str, n, &cursor, 0) == 1 || test_str(str, n, &cursor, 0) == 2 ||
				(test_str(str, n, &cursor, 0) == 3 && (valid_piece(test) || nb_c != 4)))
			return (test_str(str, n, &cursor, 0));
		if (str[n] == '\n')
			condition_n(&cursor, &test, &nb_c, 1);
		if (cursor.x > 4)
			return (1);
		if (test_str(str, n, &cursor, 0) == 3)
			condition_hard(&cursor, &nb_c, &nb_p);
		if (cursor.y > 4 || nb_c > 4)
			return (2);
		n = test_str(str, n, &cursor, 1);
	}
	return (nb_p);
}

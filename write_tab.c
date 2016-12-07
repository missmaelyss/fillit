/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparment <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:07:12 by vparment          #+#    #+#             */
/*   Updated: 2016/12/07 15:20:07 by vparment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_piece(t_piece piece, char **tab_f, t_point cursor, int s)
{
	int	n;

	n = 0;
	while (n < 4)
	{
		if (cursor.x == s || cursor.y == s)
			return (0);
		if (tab_f[cursor.y][cursor.x] != '.')
			return (0);
		if (n < 3)
		{
			cursor.x = piece.cd[n + 1].x + (cursor.x - piece.cd[n].x);
			cursor.y = piece.cd[n + 1].y + (cursor.y - piece.cd[n].y);
		}
		n++;
	}
	if (tab_f[cursor.y][cursor.x] != '.')
		return (0);
	return (1);
}

static t_point	move_cursor(t_point *cursor, int size)
{
	if (cursor->x < size - 1)
		cursor->x++;
	else
	{
		cursor->y++;
		cursor->x = 0;
	}
	return (*cursor);
}

static void		next_n(t_point *tab_cursor, t_tab *t, t_point *cursor)
{
	tab_cursor[(*t).n] = (*cursor);
	initialise_cursor(cursor);
	(*t).n++;
}

char			**write_tab(t_piece *tab, t_tab t, t_point c, t_point *t_c)
{
	while (t.n < t.nb_p)
	{
		if (check_piece(tab[t.n], t.tab_f, c, t.size))
		{
			write_piece(tab[t.n], t.tab_f, c);
			next_n(t_c, &t, &c);
		}
		else if (!(c.x == t.size - 1 && c.y == t.size - 1))
			move_cursor(&c, t.size);
		else if (t.n == 0)
		{
			initialise_cursor(&c);
			t.size++;
			free(t.tab_f);
			t.tab_f = create_tab(t.size);
		}
		else
		{
			t.n--;
			c = t_c[t.n];
			erase_piece(tab[t.n], t.tab_f, c);
			move_cursor(&c, t.size);
		}
	}
	return (t.tab_f);
}

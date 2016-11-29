/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:06:41 by marnaud           #+#    #+#             */
/*   Updated: 2016/11/24 19:55:12 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
			if (test.cd[n].x == test.cd[n2].x && test.cd[n].y == test.cd[n2].y + 1)
				nb_touch++;
			if (test.cd[n].x == test.cd[n2].x && test.cd[n].y == test.cd[n2].y - 1)
				nb_touch++;
			if (test.cd[n].y == test.cd[n2].y && test.cd[n].x == test.cd[n2].x + 1)
				nb_touch++;
			if (test.cd[n].y == test.cd[n2].y && test.cd[n].x == test.cd[n2].x - 1)
				nb_touch++;
			n2++;
		}
		n++;
	}
	if (nb_touch < 6)
		return (1);
	return (0);
}

int			valid_file(char *str)
{
	t_point		cursor;
	t_piece		test;
	int			n;
	int 		nb_c;
	int			nb_p;

	n = 0;
	nb_c = 0;
	cursor.x = 1;
	cursor.y = 1;
	nb_p = 0;
	while (str[n] != '\0')
	{
		if (str[n] != '.' && str[n] != '#' && str[n] != '\n')
			return (0);
		if (str[n] == '#')
		{
			test.cd[nb_c] = cursor;
			nb_c++;
		}
		if (str[n] == '\n')
		{
			cursor.y++;
			cursor.x = 0;
		}
		if (cursor.x > 4)
			return (0);
		if ((str[n] == '\n' && str[n + 1] == '\n' && str[n + 2] != '\n' && str[n + 2] != '\0')
				|| (str[n] == '\n' && str[n + 1] == '\0'))
		{
			if (valid_piece(test) || nb_c != 4)
				return (0);
			cursor.y = 0;
			nb_c = 0;
			nb_p++;
		}
		if (cursor.y > 4 || nb_c > 4)
			return (0);
		cursor.x++;
		n++;
	}
	return (nb_p);
}

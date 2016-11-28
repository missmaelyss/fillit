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

int			ft_valid_piece(t_piece test)
{
	int		nb_touch;
	int		n;

	nb_touch = 0;
	while (n < 4)
	{
		if (n < 3 && test.cd[n].x == test.cd[n + 1].x)
			nb_touch++;
		if (n > 0 && test.cd[n].x == test.cd[n - 1].x)
			nb_touch++;
		if (n < 3 && test.cd[n].y == test.cd[n + 1].y)
			nb_touch++;
		if (n > 0 && test.cd[n].y == test.cd[n - 1].y)
			nb_touch++;
		n++;
	}
	if (nb_touch < 6)
		return (1);
	return (0);
}

int			ft_valid_file(char *str)
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
			if (ft_valid_piece(test) || nb_c != 4)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:17:19 by marnaud           #+#    #+#             */
/*   Updated: 2016/12/05 14:02:48 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	initialisation(t_point *cursor, int *n, int *n_tab, int *n_cd)
{
	(*cursor).x = 1;
	(*cursor).y = 1;
	*n = 0;
	*n_tab = 0;
	*n_cd = 0;
}

static void	second_case(t_point *cursor)
{
	(*cursor).x = 0;
	(*cursor).y++;
}

static void	third_case(t_point *cursor, int *n_tab, int *n_cd, t_piece **tab_p)
{
	(*cursor).y = 0;
	(*n_tab)++;
	(*tab_p)[*n_tab].c = (*tab_p)[*n_tab - 1].c + 1;
	*n_cd = 0;
}

t_piece		*save_piece(char *str, int nb_p)
{
	t_piece		*tab_p;
	t_point		cursor;
	int			n;
	int			n_cd;
	int			n_tab;

	if (!(tab_p = (t_piece *)malloc(sizeof(t_piece) * (nb_p))))
		return (0);
	initialisation(&cursor, &n, &n_tab, &n_cd);
	tab_p[0].c = 'A';
	while (str[n] != '\0')
	{
		if (str[n] == '#')
		{
			tab_p[n_tab].cd[n_cd] = cursor;
			n_cd++;
		}
		if (str[n] == '\n')
			second_case(&cursor);
		if (str[n] == '\n' && str[n + 1] == '\n')
			third_case(&cursor, &n_tab, &n_cd, &tab_p);
		cursor.x++;
		n++;
	}
	return (tab_p);
}

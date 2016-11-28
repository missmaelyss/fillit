/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_piece.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:17:19 by marnaud           #+#    #+#             */
/*   Updated: 2016/11/24 20:11:54 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_piece
{
	t_point		cd[4];
	char		c;
}				t_piece;
i*/
t_piece		*ft_save_piece(char *str, int nb_p)
{
	t_piece		*tab_p;
	t_point		cursor;
	int			n;
	int			n_cd;
	int			n_tab;

	if (!(tab_p = (t_piece *)malloc(sizeof(t_piece) * (nb_p))))
		return (0);
	cursor.x = 1;
	cursor.y = 1;
	n = 0;
	n_tab = 0;
	n_cd = 0;
	tab_p[0].c = 'A';
	while (str[n] != '\0')
	{
		if (str[n] == '#')
		{
			tab_p[n_tab].cd[n_cd] = cursor;
			n_cd++;
		}
		if (str[n] == '\n')
		{
		   cursor.x = 0;
		   cursor.y++;
		}
		if (str[n] == '\n' && str[n + 1] == '\n')
		{
			cursor.y = 0;
			n_tab++;
			tab_p[n_tab].c = tab_p[n_tab - 1].c + 1;
			n_cd = 0;
		}
		cursor.x++;
		n++;
	}
	return (tab_p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:20:29 by marnaud           #+#    #+#             */
/*   Updated: 2016/12/07 16:43:24 by marnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_piece
{
	t_point	cd[4];
	char	c;
}				t_piece;

typedef struct	s_tab
{
	int		nb_p;
	int		size;
	int		n;
	int		fd;
	char	**tab_f;
}				t_tab;

void			ft_putchar(char c);
void			ft_putstr(const char *str);
int				valid_file(char *str);
t_piece			*save_piece(char *str, int nb_p);
int				valid_piece(t_piece piece);
t_piece			move_up_left(t_piece piece);
char			**create_tab(int n);
void			initialise_cursor(t_point *cursor);
char			**write_tab(t_piece *piece, t_tab tableau, t_point cursor,
		t_point *tab_cursor);
void			write_piece(t_piece piece, char **tab_f, t_point cursor);
void			erase_piece(t_piece piece, char **tab_f, t_point cursor);

#endif

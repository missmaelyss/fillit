#include "fillit.h"

char	**create_tab(int n)
{
	char	**tab_f;
	int		y;
	int		x;

	y = 0;
	if(!(tab_f = (char **)malloc(sizeof(char *) * (n + 1))))
		return(0);
	while(y < n)
	{
		if(!(tab_f[y] = (char *)malloc(sizeof(char) * (n + 1))))
			return(0);
		x = 0;
		while (x < n)
		{
			tab_f[y][x] = '.';
			x++;
		}
		tab_f[y][n] = '\0';
		y++;
	}
	tab_f[n] = 0;
	return(tab_f);
}


int		check_piece(t_piece piece, char **tab_f, t_point cursor, int size)
{		
	int	n;

	n = 0;
	while(n < 4)
	{
		if (cursor.x == size || cursor.y == size)
			return (0);
		if( tab_f[cursor.y][cursor.x] != '.')
			return(0);
		if (n < 3)
		{
			cursor.x = piece.cd[n+1].x + (cursor.x - piece.cd[n].x);
			cursor.y = piece.cd[n+1].y + (cursor.y - piece.cd[n].y);
		}
		n++;
	}
	if( tab_f[cursor.y][cursor.x] != '.')
		return(0);
	return(1);
}

void	write_piece(t_piece piece, char **tab_f, t_point cursor)
{		
	int	n;

	n = 0;
	while(n < 3)
	{
		tab_f[cursor.y][cursor.x] = piece.c;
		cursor.x = piece.cd[n+1].x + (cursor.x - piece.cd[n].x);
		cursor.y = piece.cd[n+1].y + (cursor.y - piece.cd[n].y);
		n++;
	}
	tab_f[cursor.y][cursor.x] = piece.c;
}

void	erase_piece(t_piece piece, char **tab_f, t_point cursor)
{
	int n;

	n = 0;
	while(n < 3)
	{	   
		tab_f[cursor.y][cursor.x] = '.';
		cursor.x = piece.cd[n+1].x + (cursor.x - piece.cd[n].x);
		cursor.y = piece.cd[n+1].y + (cursor.y - piece.cd[n].y);
		n++;
	}
	tab_f[cursor.y][cursor.x] = '.';
}

t_point		move_cursor(t_point *cursor, int size)
{
	if(cursor->x < size -1)
		cursor->x++;
	else
	{	
		cursor->y++;
		cursor->x = 0;
	}
	return(*cursor);
}

t_point		initialise_cursor(t_point *cursor)
{
	cursor->x = 0;
	cursor->y = 0;
	return(*cursor);
}

char	**write_tab(t_piece *tab, int nb_p, int size, int n)
{
	char	**tab_f;
	t_point	cursor;
	t_point	*tab_cursor;

	tab_cursor = (t_point *)malloc(sizeof(t_point) * nb_p);
	cursor = initialise_cursor(&cursor);
	tab_f = create_tab(size);
	while (n < nb_p)
	{
		if (check_piece(tab[n], tab_f, cursor, size)) 
		{
			write_piece(tab[n], tab_f, cursor);
			tab_cursor[n] = cursor;
			cursor = initialise_cursor(&cursor);
			n++;
		}
		else if (n == 0)
		{
			cursor = initialise_cursor(&cursor);
			size++;
			free(tab_f);
			tab_f = create_tab(size);
		}
		else 
		{
			if(cursor.x == size - 1 && cursor.y == size - 1)
			{
				n--;
				cursor = tab_cursor[n];
				erase_piece(tab[n], tab_f, cursor);
			}
			move_cursor(&cursor, size);
		}
	}
	return (tab_f);
}

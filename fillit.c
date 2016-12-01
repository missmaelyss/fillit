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
	while(n < 3)
	{
		if (cursor.x >= size || cursor.y >= size)
			return (0);
		if( tab_f[cursor.y][cursor.x] != '.')
				return(0);
		cursor.x = piece.cd[n+1].x + (cursor.x - piece.cd[n].x);
		cursor.y = piece.cd[n+1].y + (cursor.y - piece.cd[n].y);
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

char	**test(t_piece *piece, int size, t_point cursor)
{
	char	**tab;
/*	t_point	cursor;

	cursor.x = 0;
	cursor.y = 1;
*/	tab = create_tab(size);
	printf("1");
//	if(check_piece(*piece, tab, cursor, size) == 1)
//	{
		printf("yo");
		write_piece(*piece, tab, cursor);
			cursor.x = 1;
			cursor.y = 1;
			test(piece, size, cursor);
		return (tab);
/*	}
	else
	{
		if (cursor.x == size - 1 && cursor.y == size - 1)
		{
			cursor.x = 0;
			cursor.y = 0;
			test(piece, size++, cursor);
		}
		if (cursor.x == size - 1)
		{
			cursor.x = 0;
			cursor.y++;
			test(piece, size, cursor);
		}
		else
		{
			cursor.x++;
			test(piece, size, cursor);
		}
	}
	return (tab);*/
}



#ifndef	FILLIT_H

# define FILLIT_H

#include <stdlib.h>
#include <fcntl.h>

#include <stdio.h>

typedef struct	s_point
{
	int	x;
	int	y;
}		t_point;

typedef	struct	s_piece
{
	t_point	cd[4];
	char	c;
}		t_piece;

int		valid_file(char *str);
t_piece		*save_piece(char *str, int nb_p);
int		size_piece(t_piece piece);

#endif


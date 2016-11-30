#include "fillit.h"

t_piece		move_up_left(t_piece piece)
{
	int	n;
	int	val[2];
//	val contient xmin, ymin

	n = 0;
	val[0] = piece.cd[n].x;
	val[1] = piece.cd[n].y;
	while (n < 4)
	{
		if (piece.cd[n].x < val[0])
			val[0] = piece.cd[n].x;
		if (piece.cd[n].y < val[1])
			val[1] = piece.cd[n].y;
		n++;
	}
	n = 0;
	while (n < 4)
	{
		piece.cd[n].x = piece.cd[n].x + (1 - val[0]);
		piece.cd[n].y = piece.cd[n].y + (1 - val[1]);
		n++;
	}
	return (piece);
}


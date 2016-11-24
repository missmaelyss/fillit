#include <stdio.h>

typedef	struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef	struct	s_piece
{
	t_point	cd[4];
}				t_piece;

int		ft_valid_file(char *str);
t_piece	*ft_save_piece(char *str, int nb_p);

int		main(void)
{
	char	*str;
	int		nb_p;
	t_piece	*tab;
	int 	n;
	int		n2;

	str = "....\n..##\n..#.\n..#.\n\n....\n....\n..##\n..##\n\n####\n....\n....\n....\n\n....\n....\n##..\n##..\n\n.##.\n..##\n....\n....\n\n....\n.##.\n..##\n....\n\n.#..\n###.\n....\n....\n\n....\n##..\n#...\n#...\n\n....\n.##.\n..#.\n..#.";

//	printf("%s\n", str);
	nb_p = ft_valid_file(str);
	if (nb_p == 0)
		return (0);
//	tab = ft_save_piece(str, nb_p);
	n = 0;
	while (n < nb_p)
	{
		n2 = 0;
		while (n2 < 4)
		{
			printf("x = %d, y = %d\n", tab[n].cd[n2].x, tab[n].cd[n2].y);
			n2++;
		}
		printf("\n");
		n++;
	}
	return (0);
}

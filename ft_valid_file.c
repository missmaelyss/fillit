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

typedef	struct	s_point
{
	int x;
	int y;
}				t_point;

int			ft_valid_file(char *str)
{
	t_point		cursor;
	int			n;
	int 		nb_c;
	int			nb_p;

	n = 0;
	nb_c = 0;
	cursor.x = 1;
	cursor.y = 1;
	nb_p = 1;
	while (str[n] != '\0')
	{
		if (str[n] != '.' && str[n] != '#' && str[n] != '\n')
			return (0);
		if (str[n] == '#')
			nb_c++;
		if (str[n] == '\n')
		{
			cursor.y++;
			cursor.x = 0;
		}
		if (cursor.x > 4)
			return (0);
		if (str[n] == '\n' && str[n + 1] == '\n' && str[n + 2] != '\n')
		{
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

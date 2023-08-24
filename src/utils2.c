/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 10:34:13 by itopchu       #+#    #+#                 */
/*   Updated: 2023/03/31 20:59:58 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_openfile(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_free_split(char **line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		free(line[i]);
		i++;
	}
	free(line);
}

void	isometric(t_vertex *m, int c[2], t_env *e)
{
	int		t[2];
	double	v[2];

	v[0] = e->gap * 4;
	v[1] = 30.0 * M_PI / 180;
	t[0] = c[0] * e->gap;
	t[1] = c[1] * e->gap;
	m->x = (t[0] - t[1]) * cos(v[1]) * v[0];
	m->y = (t[0] + t[1]) * sin(v[1]) * v[0] - e->grid.grid[c[0]][c[1]] * v[0];
	m->z = 0;
}

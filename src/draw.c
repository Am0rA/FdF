/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 10:35:44 by itopchu       #+#    #+#                 */
/*   Updated: 2023/04/05 13:44:36 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_close(t_env *e)
{
	mlx_close_window(e->mlx);
	mlx_terminate(e->mlx);
	exit(EXIT_SUCCESS);
}

static void	my_put_pixel(mlx_image_t *img, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		mlx_put_pixel(img, x, y, color);
}

void	draw_line(t_vertex start, t_vertex end, mlx_image_t *img)
{
	float	cur[2];
	float	v[2];
	float	s[2];

	cur[0] = start.x;
	cur[1] = start.y;
	v[0] = fabs(start.x - end.x);
	v[1] = fabs(start.y - end.y);
	if (start.x < end.x)
		s[0] = 1;
	else
		s[0] = -1;
	if (start.y < end.y)
		s[1] = 1;
	else
		s[1] = -1;
	while ((int)fabs(cur[0] - end.x) > 0 || (int)fabs(cur[1] - end.y) > 0)
	{
		my_put_pixel(img, (int)cur[0], (int)cur[1], 0xFFFFFFFF);
		cur[1] += fabs(v[1] / (v[0] * v[0] + v[1] * v[1])) * s[1];
		cur[0] += fabs(v[0] / (v[0] * v[0] + v[1] * v[1])) * s[0];
	}
	my_put_pixel(img, cur[0], cur[1], 0xFFFFFFFF);
}

void	draw_grid(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->grid.width)
	{
		j = 0;
		while (j < e->grid.height)
		{
			if (i + 1 < e->grid.width)
				draw_line(e->map[i][j], e->map[i + 1][j], e->g_img);
			if (j + 1 < e->grid.height)
				draw_line(e->map[i][j + 1], e->map[i][j], e->g_img);
			j++;
		}
		i++;
	}
}

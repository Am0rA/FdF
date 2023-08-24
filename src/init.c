/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 10:34:46 by itopchu       #+#    #+#                 */
/*   Updated: 2023/03/14 22:17:36 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	**init_grid(t_env e)
{
	int	i;
	int	**grid;

	grid = (int **)malloc(sizeof(int *) * (e.grid.width));
	if (!(grid))
		error_exit("Init_grid int ** failed.", EXIT_FAILURE);
	i = 0;
	while (i < e.grid.width)
	{
		grid[i] = ft_calloc(e.grid.height, sizeof(int));
		if (!(grid[i]))
			error_exit("Init_grid e.grid.grid[i] failed.", EXIT_FAILURE);
		i++;
	}
	fill_grid(e, grid);
	return (grid);
}

void	fill_map(t_vertex **m, t_env *e)
{
	int		c[2];

	c[0] = 0;
	while (c[0] < e->grid.width)
	{
		c[1] = 0;
		while (c[1] < e->grid.height)
		{
			isometric(&m[c[0]][c[1]], c, e);
			m[c[0]][c[1]].x += WIDTH / 2 - e->grid.width / 2;
			m[c[0]][c[1]].y += HEIGHT / 10 - e->grid.width / 2;
			c[1]++;
		}
		c[0]++;
	}
}

t_vertex	**init_map(t_env *e)
{
	t_vertex	**map;
	int			i;

	map = (t_vertex **)malloc(sizeof(t_vertex *) * (e->grid.width));
	if (!map)
		error_exit("Init_map map failed", EXIT_FAILURE);
	i = 0;
	while (i < e->grid.width)
	{
		map[i] = (t_vertex *)malloc(sizeof(t_vertex) * (e->grid.height));
		if (!map[i])
			error_exit("Init_map map[i] failed", EXIT_FAILURE);
		i++;
	}
	fill_map(map, e);
	return (map);
}

void	init_tools(t_env *e)
{
	e->mlx = mlx_init(WIDTH, HEIGHT, "FdF", false);
	if (!(e->mlx))
		error_exit("mlx_init failed.", EXIT_FAILURE);
	e->g_img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	if (!(e->g_img))
		error_exit("mlx_new_image failed.", EXIT_FAILURE);
	e->win = mlx_image_to_window(e->mlx, e->g_img, 0, 0);
	if (e->win < 0)
		error_exit("mlx_image_to_window failed.", EXIT_FAILURE);
}

void	init_env(t_env *e, int fd)
{
	e->input = read_file(fd);
	close(fd);
	if (!e->input)
		error_exit("Empty map.", EXIT_FAILURE);
	e->grid.width = list_width(e->input);
	e->grid.height = list_height(e->input);
	e->grid.grid = init_grid(*e);
	e->gap = 3;
	e->map = init_map(e);
	init_tools(e);
}

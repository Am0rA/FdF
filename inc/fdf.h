/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/11 19:34:39 by itopchu       #+#    #+#                 */
/*   Updated: 2023/03/14 20:11:40 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mylib/src/header/ft_printf.h"
# include "mylib/src/header/get_next_line.h"
# include "mylib/src/header/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
// # include "MLX42/include/MLX42/MLX42_Input.h"
// # include "MLX42/include/MLX42/MLX42_Int.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_bresenham
{
	int	x;
	int	y;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

typedef struct s_vertex
{
	double	x;
	double	y;
	double	z;
}	t_vertex;

typedef struct s_grid
{
	int	width;
	int	height;
	int	**grid;
}	t_grid;

typedef struct s_env
{
	int			gap;
	t_grid		grid;
	t_list		*input;
	t_vertex	**map;
	mlx_image_t	*g_img;
	mlx_t		*mlx;
	int32_t		win;
}	t_env;

/*==================================*/
/*				DRAW				*/
/*==================================*/
void		error_exit(char *str, int status);
void		check_extention(char *s);

/*==================================*/
/*				DRAW				*/
/*==================================*/
void		ft_close(t_env *e);
void		draw_grid(t_env *e);

/*==================================*/
/*				INIT				*/
/*==================================*/
int			**init_grid(t_env e);
void		fill_map(t_vertex **map, t_env *e);
t_vertex	**init_map(t_env *e);
void		init_tools(t_env *e);
void		init_env(t_env *e, int fd);

/*==================================*/
/*				MAIN				*/
/*==================================*/
int			main(int ac, char **av);

/*==================================*/
/*				UTILS				*/
/*==================================*/
t_list		*read_file(int fd);
int			list_width(t_list *l);
int			list_height(t_list *l);
void		fill_grid(t_env e, int **grid);

/*==================================*/
/*				UTILS2				*/
/*==================================*/
int			ft_openfile(char *s);
void		ft_free_split(char **line);
void		isometric(t_vertex *m, int c[2], t_env *e);

#endif

/* ************************************************************************** */
/*																			*/
/*														::::::::			*/
/*   main.c											 :+:	:+:			*/
/*													 +:+					*/
/*   By: itopchu <itopchu@student.codam.nl>		   +#+					 */
/*												   +#+					  */
/*   Created: 2023/01/11 19:31:34 by itopchu	   #+#	#+#				 */
/*   Updated: 2023/01/30 17:20:57 by itopchu	   ########   odam.nl		 */
/*																			*/
/* ************************************************************************** */

#include "../inc/fdf.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*env;

	env = param;
	if (keydata.action == MLX_PRESS)
		write(1, "PRESSED\n", 8);
	if (mlx_is_key_down(env->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(env->mlx);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac != 2)
		error_exit("Wrong input.\nExpected: ./fdf file.fdf", EXIT_FAILURE);
	check_extention(av[1]);
	init_env(&env, ft_openfile(av[1]));
	draw_grid(&env);
	mlx_key_hook(env.mlx, &my_keyhook, &env);
	mlx_loop(env.mlx);
	mlx_terminate(env.mlx);
	return (0);
}

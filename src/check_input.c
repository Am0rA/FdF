/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 11:51:06 by itopchu       #+#    #+#                 */
/*   Updated: 2023/03/18 13:42:31 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	error_exit(char *str, int status)
{
	write(STDERR_FILENO, "Error : ", 8);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, "\n", 1);
	exit(status);
}

void	check_extention(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (i < 5)
		error_exit("Wrong file name", EXIT_FAILURE);
	i = i - 4;
	if (ft_strncmp(&s[i], ".fdf", 5) != 0)
		error_exit("Wrong extension,", EXIT_FAILURE);
}

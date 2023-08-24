/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: itopchu <itopchu@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 10:34:23 by itopchu       #+#    #+#                 */
/*   Updated: 2023/03/08 10:34:28 by itopchu       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_list	*read_file(int fd)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(*tmp));
	if (!tmp)
		error_exit("List malloc failed", EXIT_FAILURE);
	tmp->content = get_next_line(fd);
	if (tmp->content == NULL)
	{
		free(tmp);
		return (NULL);
	}
	tmp->next = read_file(fd);
	return (tmp);
}

int	list_width(t_list *l)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(l->content, ' ');
	if (!split)
		error_exit("List width failed.", EXIT_FAILURE);
	while (split[i])
		i++;
	ft_free_split(split);
	return (i);
}

int	list_height(t_list *l)
{
	t_list	*t;
	int		i;

	i = 0;
	t = l;
	while (t)
	{
		i++;
		t = t->next;
	}
	return (i);
}

void	fill_grid(t_env e, int **grid)
{
	char	**split;
	t_list	*l;
	int		i;
	int		j;

	j = 0;
	l = e.input;
	while (l && j < e.grid.height)
	{
		split = ft_split(l->content, ' ');
		if (!split)
			error_exit("fill_grid split failed.", EXIT_FAILURE);
		i = 0;
		while (split[i] && i < e.grid.width)
		{
			grid[i][j] = ft_atoi(split[i]);
			i++;
		}
		ft_free_split(split);
		j++;
		l = l->next;
	}
}

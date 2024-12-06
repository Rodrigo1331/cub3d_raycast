/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:01:22 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/06 11:14:05 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


static void	free_game_mlx(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->img[i].img)
			mlx_destroy_image(game->mlx, game->img[i].img);
	if (game->screen.img)
		mlx_destroy_image(game->mlx, game->screen.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	free_game(t_game *game)
{
	int	i;

	if (!game)
		return (0);
	if (game->mlx)
		free_game_mlx(game);
	if (game->file_line)
		free(game->file_line);
	i = -1;
	while (++i < 4)
		if (game->textures[i])
			free(game->textures[i]);
	if (game->map)
		ft_free_array(game->map);
	exit(0);
}

int	exit_error(t_game *game, char *message)
{
	ft_putendl_fd(RED"Error", 2);
	ft_putendl_fd(message, 2);
	ft_putstr_fd(RESET, 2);
	free_game(game);
	exit(errno);
}
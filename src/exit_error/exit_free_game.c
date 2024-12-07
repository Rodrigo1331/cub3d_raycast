/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:01:22 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/07 10:43:35 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* static void	free_textures(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->textures[i])
			free(game->textures[i]);
} */

static void	free_mlx(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->img_text[i].img)
			mlx_destroy_image(game->mlx, game->img_text[i].img);
	if (game->pixels.img)
		mlx_destroy_image(game->mlx, game->pixels.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_tokens(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 7)
		if (game->tokens_params[i])
			free(game->tokens_params[i]);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->mlx)
			free_mlx(game);
		if (game->map.grid)
			ft_free_array(game->map.grid);
		if (game->tmp_map_grid)
			free(game->tmp_map_grid);
		free_tokens(game);
	}
	exit(EXIT_SUCCESS);
}

int	exit_x(t_game *game)
{
	ft_putendl_fd("You gave up! See you soon!", 1);
	free_game(game);
	exit(EXIT_SUCCESS);
}

void	exit_error(t_game *game, char *msg)
{
	ft_putendl_fd("\nError: ", 2);
	ft_putendl_fd(msg, 2);
	free_game(game);
}

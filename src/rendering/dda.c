/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:49 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/07 11:12:03 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* ray.side = 1 */
/* x positive --> = 1 */
/* x negative --> = 0 */

/* ray.side = 3 */
/* y positive --> = 3 */
/* y negative --> = 2 */
static void	check_collision(t_game *game, t_2d_grid checker)
{
	if (game->map.grid[checker.y][checker.x] != '0'
		&& !ft_strrchr("NSWE", game->map.grid[checker.y][checker.x]))
	{
		game->ray.reached_wall = game->ray.side - (game->ray.side == 1
				&& game->ray.step_x < 0) - (game->ray.side == 3
				&& game->ray.step_y < 0);
	}
}

/* Calculate the distance from the plane to
the wall hit (parallel to the ray_dir)  */
static void	hit_length(t_game *game)
{
	double	hit_x;

	if (game->ray.side == 1)
		game->ray.perp_wall_dist = game->ray.side_dist_x
			- game->ray.delta_dist_x;
	else
		game->ray.perp_wall_dist = game->ray.side_dist_y
			- game->ray.delta_dist_y;
	if (game->ray.side == 1)
		hit_x = game->player.y + game->ray.perp_wall_dist * game->ray.dir_y;
	else
		hit_x = game->player.x + game->ray.perp_wall_dist * game->ray.dir_x;
	hit_x -= floor(hit_x);
	game->ray.hit = (int)(hit_x * (double)TEXTURE_WIDTH);
	if (game->ray.reached_wall == 0)
		game->ray.hit = TEXTURE_WIDTH - game->ray.hit - 1;
	if (game->ray.reached_wall == 3)
		game->ray.hit = TEXTURE_WIDTH - game->ray.hit - 1;
}

static void	draw_walls_data(t_game *game)
{
	game->draw.line_height = fabs((double)SCREEN_HEIGHT
			/ game->ray.perp_wall_dist);
	game->draw.start = SCREEN_HEIGHT / 2 - game->draw.line_height / 2;
	if (game->draw.start < 0)
		game->draw.start = 0;
	game->draw.end = SCREEN_HEIGHT / 2 + game->draw.line_height / 2;
	if (game->draw.end >= SCREEN_HEIGHT)
		game->draw.end = SCREEN_HEIGHT - 1;
	game->draw.step = 1.0 * TEXTURE_HEIGHT / game->draw.line_height;
	game->draw.pos = (game->draw.start - (double)SCREEN_HEIGHT / 2
			+ (double)game->draw.line_height / 2) * game->draw.step;
}

static void	each_delta_step(t_game *game)
{
	if (game->ray.side_dist_x < game->ray.side_dist_y)
	{
		game->ray.side = 1;
		game->ray.side_dist_x += game->ray.delta_dist_x;
		game->map.checker.x += game->ray.step_x;
	}
	else
	{
		game->ray.side = 3;
		game->ray.side_dist_y += game->ray.delta_dist_y;
		game->map.checker.y += game->ray.step_y;
	}
	check_collision(game, game->map.checker);
}

/* DDA --> Digital Differential Analysis */
void	dda_calculations(t_game *game)
{
	game->ray.side = 0;
	while (game->ray.reached_wall == -1)
		each_delta_step(game);
	hit_length(game);
	draw_walls_data(game);
}

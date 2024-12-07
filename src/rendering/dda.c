/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:00:49 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/04 16:58:13 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* ray.side = 1 */
/* x positive --> = 1 */
/* x negative --> = 0 */

/* ray.side = 3 */
/* y positive --> = 3 */
/* y negative --> = 2 */
static void check_collision(t_game *game, t_2d_grid checker)
{
    if (game->map.grid[checker.y][checker.x] != '0')
    {
        game->ray.reached_wall = game->ray.side - (game->ray.side == 1 && 
        game->ray.step_x < 0) - (game->ray.side == 3 && game->ray.step_y < 0);
    }
}

/* Calculate the distance from the plane to the wall hit (parallel to the ray_dir)  */
static void hit_length(t_game *game)
{
    double hit_x;

    if (game->ray.side == 1)
        game->ray.perp_wall_dist = game->ray.side_dist_x - game->ray.delta_dist_x; //Distance traveled along the ray X
    else
        game->ray.perp_wall_dist = game->ray.side_dist_y - game->ray.delta_dist_y;
    if (game->ray.side == 1)
        hit_x = game->player.y + game->ray.perp_wall_dist * game->ray.dir_y; // Hit position
    else
        hit_x = game->player.x + game->ray.perp_wall_dist * game->ray.dir_x;
    hit_x -= floor(hit_x); //INT less or equal to hit (in x);
    game->ray.hit = (int)(hit_x * (double)TEXTURE_WIDTH);
    if (game->ray.reached_wall == 0) // On a vertical wall, if the ray hits the left side
		game->ray.hit = TEXTURE_WIDTH - game->ray.hit - 1; //Flip the texture coordinate if the wall hits the opposite side (negative)
	if (game->ray.reached_wall == 3) // On a horizontal wall, if the ray hits the bottom side
		game->ray.hit = TEXTURE_WIDTH - game->ray.hit - 1; //Flip the texture coordinate if the wall hits the opposite side (positive)
}

static void draw_walls_data(t_game *game)
{
	game->draw.line_height = fabs((double)SCREEN_HEIGHT / game->ray.perp_wall_dist); //The further the wall is, the smaller it will be
	game->draw.start = SCREEN_HEIGHT / 2 - game->draw.line_height / 2; //Center the wall --> Move upwards half of the wall height (reach the top of the wall) //Pitch is for looking up or down
	if (game->draw.start < 0) //Doesn't start above the top of the screen
		game->draw.start = 0; 
	game->draw.end = SCREEN_HEIGHT / 2 + game->draw.line_height / 2; //Same logic as game->draw->start
	if (game->draw.end >= SCREEN_HEIGHT) //Doesn't start under the bottom of the screen
		game->draw.end = SCREEN_HEIGHT - 1;	
	game->draw.step = 1.0 * TEXTURE_HEIGHT / game->draw.line_height; //Ensures that the entire texture height is mapped proportionally to the wall slice height on the screen.
													 //Multiply by 1.0 to force division with float (decimal)
	game->draw.pos = (game->draw.start - (double)SCREEN_HEIGHT / 2 //A bit confused on this one
				+ (double)game->draw.line_height / 2) * game->draw.step;	         //Translates the vertical screen space (pixels) into the vertical texture space (coordinates).
}

static void each_delta_step(t_game *game)
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
void dda_calculations(t_game *game)
{
    game->ray.side = 0;
    while(game->ray.reached_wall == -1)
        each_delta_step(game);
    hit_length(game);
    draw_walls_data(game);
}

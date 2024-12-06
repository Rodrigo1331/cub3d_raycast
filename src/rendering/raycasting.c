/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:59:28 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/04 16:57:55 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Upper half will be the ceiling COLOR, the bottom half will be the floor COLOR*/
void draw_background(t_game *game)
{
    int x;
    int y;

    x = -1;
    y = -1;
    while (++y < SCREEN_HEIGHT)
    {
        while (++x < SCREEN_WIDTH)
        {
            if (y > SCREEN_HEIGHT / 2)
                put_pixil(game, x, y, game->color[flr]);
            else
                put_pixil(game, x, y, game->color[clg]);
        }
        x = -1;
    }
}

/* fabs() --> absolute value */
/* delta_dist.y = fabs(1/ray_dir.y) */
static void init_dda(t_game *game)
{
    game->ray.reached_wall = -1; //For DDA
    game->pl.delta_dist.x = 1e30 * (game->pl.ray_dir.x == 0) // If ray_dir is 0 (parallel to x-axis), set the distance to a high value number to avoid division by 0
        + fabs(1.0 / (game->pl.ray_dir.x + (game->pl.ray_dir.x == 0))); //Formula --> delta_dist.x = fabs(1/ray_dir.x)
    game->pl.delta_dist.y = 1e30 * (game->pl.ray_dir.y == 0)
        + fabs(1.0 / (game->pl.ray_dir.y + (game->pl.ray_dir.y == 0)));
    game->pl.side_dist.x = fabs((game->pl.pos.x - game->check.x)        //Exact position on the grid cell
                    - (game->pl.ray_dir.x > 0)) * game->pl.delta_dist.x; // (ray_dir.x > 0) based whether the next grid cell is in the positive or negative direction
                                                                       // *delta to convert map units into screen_width
    game->pl.side_dist.y = fabs((game->pl.pos.y - game->check.y)
                    - (game->pl.ray_dir.y > 0)) * game->pl.delta_dist.y;
}

static void init_raycast(t_game *game, int x)
{
    game->ray.camera_x = 2 * x / (double)game->screen.width -1; //[-1, 1] // -1 is the leftmost side of the screen
    game->pl.ray_dir.x = game->pl.dir.x + game->pl.plane.x * game->ray.camera_x; //Ray direction in x (left to right based on camera_x value)
    game->pl.ray_dir.y = game->pl.dir.y + game->pl.plane.y * game->ray.camera_x; //Ray direction in y
    game->pl.step.x = (game->pl.ray_dir.x < 0) * -2 + 1; // -1 or 1 (left or right)
    game->pl.step.y = (game->pl.ray_dir.y < 0) * -2 + 1; // -1 or 1 (down or up)
    game->check.x = (int)(game->pl.pos.x); //Player's position as an INT to identify the grid cell (map block)
    game->check.y = (int)(game->pl.pos.y);
}

/* Raycasting loop */
int raycast(t_game *game)
{
    int horizontal_pixels;
    
    game->screen.width = SCREEN_WIDTH;
    horizontal_pixels = 0;
    handle_keys(game);
    draw_background(game);
    while (game->screen.width > horizontal_pixels++)
    {
        init_raycast(game, horizontal_pixels);
        init_dda(game);
        dda_calculations(game);
        draw(game, horizontal_pixels);
    }
    mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0); // Put image to window
    sleep(3);
    return 0;
}
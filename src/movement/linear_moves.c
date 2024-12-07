/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:09:03 by joaosilva         #+#    #+#             */
/*   Updated: 2024/11/21 13:15:14 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    move_forward(t_game *game)
{
    char    is_obstacle;

    game->player.new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
    game->player.new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
    is_obstacle = game->map.grid[(int)game->player.new_y][(int)game->player.x];
    if (is_obstacle != '1')
        game->player.y = game->player.new_y;
    is_obstacle = game->map.grid[(int)game->player.y][(int)game->player.new_x];
    if (is_obstacle != '1')
        game->player.x = game->player.new_x;
}

void    move_backward(t_game *game)
{
    char    is_obstacle;

    game->player.new_x = game->player.x + game->player.dir_x * MOVE_SPEED * -1;
    game->player.new_y = game->player.y + game->player.dir_y * MOVE_SPEED * -1;
    is_obstacle = game->map.grid[(int)game->player.new_y][(int)game->player.x];
    if (is_obstacle != '1')
        game->player.y = game->player.new_y;
    is_obstacle = game->map.grid[(int)game->player.y][(int)game->player.new_x];
    if (is_obstacle != '1')
        game->player.x = game->player.new_x;
}

void    strafe_left(t_game *game)
{
    char    is_obstacle;

    game->player.new_x = game->player.x + game->player.plane_x * MOVE_SPEED * -1;
    game->player.new_y = game->player.y + game->player.plane_y * MOVE_SPEED * -1;
    is_obstacle = game->map.grid[(int)game->player.new_y][(int)game->player.x];
    if (is_obstacle != '1')
        game->player.y = game->player.new_y;
    is_obstacle = game->map.grid[(int)game->player.y][(int)game->player.new_x];
    if (is_obstacle != '1')
        game->player.x = game->player.new_x;
}

void    strafe_right(t_game *game)
{
    char    is_obstacle;

    game->player.new_x = game->player.x + game->player.plane_x * MOVE_SPEED;
    game->player.new_y = game->player.y + game->player.plane_y * MOVE_SPEED;
    is_obstacle = game->map.grid[(int)game->player.new_y][(int)game->player.x];
    if (is_obstacle != '1')
        game->player.y = game->player.new_y;
    is_obstacle = game->map.grid[(int)game->player.y][(int)game->player.new_x];
    if (is_obstacle != '1')
        game->player.x = game->player.new_x;
}

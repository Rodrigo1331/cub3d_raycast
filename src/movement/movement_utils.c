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

void move_forward(t_game *game)
{
    char is_obstacle;

    game->pl.new_pos.x = game->pl.pos.x + game->pl.dir.x * MOVE_SPEED; //Next pl position
    game->pl.new_pos.y = game->pl.pos.y + game->pl.dir.y * MOVE_SPEED; //MOVE_SPEED == game->pl.move_speed
    is_obstacle = game->map[(int)game->pl.new_pos.y][(int)game->pl.pos.x];   //It's not an obstical (in X)
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.y = game->pl.new_pos.y;
    is_obstacle = game->map[(int)game->pl.pos.y][(int)game->pl.new_pos.x];   //It's not an obstical (in Y)
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.x = game->pl.new_pos.x;
}

void move_backward(t_game *game)
{
    char is_obstacle;

    game->pl.new_pos.x = game->pl.pos.x + game->pl.dir.x * MOVE_SPEED * -1; //game->pl.move_speed  //Next pl position
    game->pl.new_pos.y = game->pl.pos.y + game->pl.dir.y * MOVE_SPEED * -1; //-1 to move backwards
    is_obstacle = game->map[(int)game->pl.new_pos.y][(int)game->pl.pos.x];
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.y = game->pl.new_pos.y;
    is_obstacle = game->map[(int)game->pl.pos.y][(int)game->pl.new_pos.x];
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.x = game->pl.new_pos.x;
}

void strafe_left(t_game *game)
{
    char is_obstacle;

    game->pl.new_pos.x = game->pl.pos.x + game->pl.plane.x * MOVE_SPEED * -1; //Use the plane instead of the Pl's direction
    game->pl.new_pos.y = game->pl.pos.y + game->pl.plane.y * MOVE_SPEED * -1;
    is_obstacle = game->map[(int)game->pl.new_pos.y][(int)game->pl.pos.x];
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.y = game->pl.new_pos.y;
    is_obstacle = game->map[(int)game->pl.pos.y][(int)game->pl.new_pos.x];
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.x = game->pl.new_pos.x;
}

void strafe_right(t_game *game)
{
    char is_obstacle;

    game->pl.new_pos.x = game->pl.pos.x + game->pl.plane.x * MOVE_SPEED;
    game->pl.new_pos.y = game->pl.pos.y + game->pl.plane.y * MOVE_SPEED;
    is_obstacle = game->map[(int)game->pl.new_pos.y][(int)game->pl.pos.x];
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.y = game->pl.new_pos.y;
    is_obstacle = game->map[(int)game->pl.pos.y][(int)game->pl.new_pos.x];
    if (is_obstacle == '0' || is_obstacle == ' ')
        game->pl.pos.x = game->pl.new_pos.x;
}

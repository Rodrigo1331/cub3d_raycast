/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:58:36 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/04 16:58:26 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	handle_keys(t_game *game)
{
	if (game->keys.esc >= 1)
		exit_x(game);
	if (game->keys.w)
		move_forward(game);
	if (game->keys.s)
		move_backward(game);
	if (game->keys.a)
		strafe_left(game);
	if (game->keys.d)
		strafe_right(game);
	if (game->keys.rotate_left)
		rotate_left(game);
	if (game->keys.rotate_right)
		rotate_right(game);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->keys.w = 0;
	else if (keycode == A)
		game->keys.a = 0;
	else if (keycode == S)
		game->keys.s = 0;
	else if (keycode == D)
		game->keys.d = 0;
	else if (keycode == ROTATE_LEFT)
		game->keys.rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		game->keys.rotate_right = 0;
	else if (keycode == ESC)
		game->keys.esc += 1;
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->keys.w = 1;
	else if (keycode == A)
		game->keys.a = 1;
	else if (keycode == S)
		game->keys.s = 1;
	else if (keycode == D)
		game->keys.d = 1;
	else if (keycode == ROTATE_LEFT)
		game->keys.rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		game->keys.rotate_right = 1;
	return (0);
}

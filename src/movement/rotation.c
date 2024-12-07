/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:58:59 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/07 10:15:40 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/* Rotation matrix */

// [ cos(a) - sin(a) ]
// [ sin(a) + cos(a) ]

void	rotate_right(t_game *game)
{
	double	sin_;
	double	cos_;
	double	old_dir_x;
	double	old_plane_x;

	sin_ = SIN;
	cos_ = COS;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos_ - game->player.dir_y * sin_;
	game->player.dir_y = old_dir_x * sin_ + game->player.dir_y * cos_;
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * \
		cos_ - game->player.plane_y * sin_;
	game->player.plane_y = old_plane_x * sin_ + game->player.plane_y * cos_;
}

/* Igual ao de cima */
void	rotate_left(t_game *game)
{
	double	sin_;
	double	cos_;
	double	old_dir_x;
	double	old_plane_x;

	sin_ = -SIN;
	cos_ = COS;
	old_dir_x = game->player.dir_x;
	game->player.dir_x = game->player.dir_x * cos_ - game->player.dir_y * sin_;
	game->player.dir_y = old_dir_x * sin_ + game->player.dir_y * cos_;
	old_plane_x = game->player.plane_x;
	game->player.plane_x = game->player.plane_x * \
		cos_ - game->player.plane_y * sin_;
	game->player.plane_y = old_plane_x * sin_ + game->player.plane_y * cos_;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:59:19 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/07 11:03:59 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	get_pixil(t_texture *texture, int x, int y)
{
	return (*(unsigned int *)(texture->addr + \
		(y * texture->len) + (x * (texture->bits_per_pixel / 8))));
}

void	put_pixil(t_game *game, int x, int y, int color)
{
	char	*dest;

	dest = game->pixels.addr + (y * game->pixels.len + x
			* (game->pixels.bits_per_pixel / 8));
	*(unsigned int *)dest = color;
}

/* make it darker the further it is from the player */
int	darken_color(int color, double perp_wall_dist)
{
	int	r;
	int	g;
	int	b;

	perp_wall_dist /= 5;
	if (perp_wall_dist < 1)
		return (color);
	r = (color >> 16) / perp_wall_dist;
	g = (color >> 8 & 0xFF) / perp_wall_dist;
	b = (color & 0xFF) / perp_wall_dist;
	return (r << 16 | g << 8 | b);
}

void	draw(t_game *game, int x)
{
	int				y;
	int				tex_y;
	unsigned int	color;

	y = game->draw.start;
	while (y < game->draw.end)
	{
		tex_y = (int)game->draw.pos & (TEXTURE_HEIGHT - 1);
		game->draw.pos += game->draw.step;
		color = get_pixil(&game->img_text[game->ray.reached_wall],
				game->ray.hit, tex_y);
		color = darken_color(color, game->ray.perp_wall_dist);
		put_pixil(game, x, y, color);
		y++;
	}
}

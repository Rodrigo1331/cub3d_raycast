/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:43:08 by luide-so          #+#    #+#             */
/*   Updated: 2024/12/06 11:17:28 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_open(t_game *game, char *file, char *extension)
{
	int	fd;
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, extension, 4) || len < 5)
		return (exit_error(game, "Invalid texture extension"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (exit_error(game, "Failed to open texture"));
	return (fd);
}

static int	assign_texture(t_game *game, t_texture texture, char **tokens)
{
	if (game->textures[texture])
		return (exit_error(game, "Texture duplicated"));
	if (!tokens[1] || tokens[2])
		return (exit_error(game, "Invalid texture path"));
	close(check_open(game, tokens[1], ".xpm"));
	game->textures[texture] = ft_strdup(tokens[1]);
	if (!game->textures[texture])
		return (exit_error(game, "Failed to assign texture"));
	return (true);
}

static int	assign_color(t_game *game, t_color color, char **tokens)
{
	int	i;
	int	j;
	int	rgb[3];

	if (game->color[color])
		return (exit_error(game, "Color duplicated"));
	i = 0;
	while (tokens[++i])
	{
		j = -1;
		while (tokens[i][++j] || j == 0)
			if (!ft_isdigit(tokens[i][j]))
				return (exit_error(game, "Invalid color number"));
	}
	if (i != 4)
		return (exit_error(game, "RGB color must have 3 values"));
	i = -1;
	while (++i < 3)
	{
		rgb[i] = ft_atoi(tokens[i + 1]);
		if (rgb[i] < 0 || rgb[i] > 255)
			return (exit_error(game, "Invalid color range"));
	}
	game->color[color] = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	return (true);
}

int	lexer(t_game *game, char **tokens)
{
	if (!ft_strncmp(tokens[0], "NO", 3))
		return (assign_texture(game, no, tokens));
	if (!ft_strncmp(tokens[0], "SO", 3))
		return (assign_texture(game, so, tokens));
	if (!ft_strncmp(tokens[0], "WE", 3))
		return (assign_texture(game, we, tokens));
	if (!ft_strncmp(tokens[0], "EA", 3))
		return (assign_texture(game, ea, tokens));
	if (!ft_strncmp(tokens[0], "C", 2))
		return (assign_color(game, clg, tokens));
	if (!ft_strncmp(tokens[0], "F", 2))
		return (assign_color(game, flr, tokens));
	return (exit_error(game, "Invalid parameter"));
}
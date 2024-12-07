/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:42:01 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/04 16:28:28 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
MAP EXAMPLE:

F 220,100,0
C 225,30,0
NO ./textures/1.xpm
SO ./textures/0.xpm
WE ./textures/W.xpm
EA ./textures/E.xpm

1111111111111111
1e000000000000101
1e0000000000002W1
1e0000000000001k1
1111111111111111

check_textures:
Validates if the path of the textures is right:
1. Starts with NO(space), SO(space),
.. EA(space), or WE(space) and ends with .xpm.

check_colors:
1. Verify the commas in the color RGB
2. Verify that color is inside 0-255 RGB.

check_map:
// check_characters:
// 1. Verify if the map has only valid characters.
// 2. Verify if the map is surrounded by walls.
// 3. Verify if there is only one player, ...
// ... eg, only one 'N', 'S', 'E', 'W'.


// parse_check_assign_textures DELETED
1. Verifies duplicates. If it is a duplicate, the
2. Verifies if the path is valid.
3. Verifies if the file can be opened.
4. Assigns the texture.

void	parse_check_assign_textures(t_game *game, const char *path,
		int texture_index, char *file)
{
	int	fd;

	if (game->textures[texture_index].path != NULL)
		exit_error(game, "Error\nDuplicate texture assignment.\n");
	if (!ft_strcmp(file + ft_strlen(file) - 4, ".xpm", 4) || strlen(file) < 5)
		exit_error(game, "Invalid name or texture extension.\n");
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_error(game, "Error\nCannot open texture file.\n");
	close(fd);
	game->textures[texture_index].path = ft_strdup(path);
}
*/

/*
1. First it splits the line by the comma.
2. Then it verifies if the split is valid.
3. Then it verifies if the RGB is valid:
	- Using a while it verifies if every
	char of the str is a digit.
	- If it has more than 3 characters.
	- If it is between 0 and 255.
4. If it is valid, it assigns the RGB to the array.
5. If it is not valid, it frees the split and returns 0.
*/
int	parse_color_2(char *color_element)
{
	int	j;

	j = 0;
	while (color_element[j])
	{
		if (!ft_isdigit(color_element[j]))
			return (0);
		j++;
	}
	if (ft_strlen(color_element) > 3)
		return (0);
	return (1);
}

int	parse_color(char *line, int *rgb)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ',');
	if (!split)
		return (0);
	while (split[i])
	{
		if (!parse_color_2(split[i]))
		{
			ft_free_array(split);
			return (0);
		}
		rgb[i] = ft_atoi(split[i]);
		if (rgb[i] < 0 || rgb[i] > 255)
		{
			ft_free_array(split);
			return (0);
		}
		i++;
	}
	ft_free_array(split);
	return (i == 3);
}

/*
1. Verifies if it is a valid color.
2. Verifies if the color is already assigned.
3. Assigns the color.
*/
void	parse_check_assign_colors(t_game *game, char *token, char c)
{
	int	rgb[3];

	if (!parse_color(token, rgb))
		exit_error(game, "Invalid color format.\n");
	if (c == 'C')
	{
		if (game->ceiling_color != -1)
			exit_error(game, "Ceiling color is already assigned.\n");
		game->ceiling_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
	else if (c == 'F')
	{
		if (game->floor_color != -1)
			exit_error(game, "Floor color is already assigned.\n");
		game->floor_color = (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
	}
}

/*
1. Assigns all the textures and colors to the game struct.
2. Each function verifies if the assignment is valid,
and if the assignment is not valid, it exits the program.
3. If all the assignments are valid, it continues and
gives free to the tokens_params.
*/
void	lexer(t_game *game)
{
	int	i;

	i = -1;
	while (game->tokens_params[++i])
	{
		if (ft_strncmp(game->tokens_params[i], "NO ", 3) == 0)
			game->textures[3] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "SO ", 3) == 0)
			game->textures[2] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "EA ", 3) == 0)
			game->textures[0] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "WE ", 3) == 0)
			game->textures[1] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "F ", 2) == 0)
			parse_check_assign_colors(game, game->tokens_params[i] + 2, 'F');
		else if (ft_strncmp(game->tokens_params[i], "C ", 2) == 0)
			parse_check_assign_colors(game, game->tokens_params[i] + 2, 'C');
		else
			exit_error(game, "Unknown parameter.\n");
	}
}

/* void	lexer(t_game *game)
{
	int	i;

	i = -1;
	while (game->tokens_params[++i])
	{
		if (ft_strncmp(game->tokens_params[i], "NO ", 3) == 0)
			game->textures[0] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "SO ", 3) == 0)
			game->textures[1] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "EA ", 3) == 0)
			game->textures[2] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "WE ", 3) == 0)
			game->textures[3] = &(game->tokens_params[i][3]);
		else if (ft_strncmp(game->tokens_params[i], "F ", 2) == 0)
			parse_check_assign_colors(game, game->tokens_params[i] + 2, 'F');
		else if (ft_strncmp(game->tokens_params[i], "C ", 2) == 0)
			parse_check_assign_colors(game, game->tokens_params[i] + 2, 'C');
		else
			exit_error(game, "Unknown parameter.\n");
	}
} */

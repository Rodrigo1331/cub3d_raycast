/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:55:55 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/04 22:08:29 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_map_walls_floodfill(t_game *game, const int x, const int y)
{
	if (x < 0 || y < 0 || game->map.grid[y] == NULL
		|| x >= (int)ft_strlen(game->map.grid[y])
		|| game->map.grid[y][x] == ' ')
	{
		exit_error(game, "Map is not surrounded by walls.\n");
	}
	if (game->map.grid[y][x] == WALL)
		return ;
	game->map.grid[y][x] = '1';
	check_map_walls_floodfill(game, x + 1, y);
	check_map_walls_floodfill(game, x - 1, y);
	check_map_walls_floodfill(game, x, y + 1);
	check_map_walls_floodfill(game, x, y - 1);
}

void	set_spawn(t_game *game, int i, int j)
{
	while (game->map.grid[i])
	{
		j = 0;
		while (game->map.grid[i][j])
		{
			if (ft_strchr("NSEW", game->map.grid[i][j]))
			{
				if (game->player.x != 0 || game->player.y != 0)
					exit_error(game, "Multiple player spawn points found.\n");
				game->player.x = j + 0.5;
				game->player.y = i + 0.5;
				game->player.dir_x = (game->map.grid[i][j] == 'E')
					- (game->map.grid[i][j] == 'W');
				game->player.dir_y = (game->map.grid[i][j] == 'S')
					- (game->map.grid[i][j] == 'N');
				game->player.plane_x = (game->player.dir_y * FOV) * -1;
				game->player.plane_y = game->player.dir_x * FOV;
				game->map.grid[i][j] = FLOOR;
			}
			j++;
		}
		i++;
	}
	if (game->player.x == 0 || game->player.y == 0)
		exit_error(game, "Valid player spawn point not found.\n");
}

int	check_map_characters(t_game *game)
{
	char	*line;

	line = game->tmp_map_grid;
	while (*line)
	{
		if (!ft_strchr(" 01NSWE\n", *line))
		{
			printf("Invalid map character: %c\n", *line);
			exit_error(game, "Invalid map character.\n");
			return (1);
		}
		line++;
	}
	return (0);
}

void	check_empty_line_in_map(t_game *game)
{
	char	*map;
	int		last_line_len;

	map = game->tmp_map_grid; // map é o mapa temporário
	while (*map)
	{
		last_line_len = ft_strclen(map, '\n');
		// Verificar se há uma linha vazia seguida por uma linha não vazia
		if (!last_line_len && ft_strclen(map + 1, '\n'))
			exit_error(game,
				"Invalid map: number found after map and empty line.\n");
		map += last_line_len;
		if (*map == '\n') // Avançar o ponteiro se o caractere atual for '\n'
			map++;
	}
	// Verificar se o último caractere do mapa é '\0' após o processamento
	if (last_line_len > 0 && game->tmp_map_grid[last_line_len - 1] == '\0')
		return; // Mapa válido
}

void	parse_check_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	check_map_characters(game);
	check_empty_line_in_map(game);
	game->map.grid = ft_split(game->tmp_map_grid, '\n');
	if (!game->map.grid)
		exit_error(game, "Memory allocation failed in ft_split.\n");
	set_spawn(game, i, j);
	check_map_walls_floodfill(game, game->player.x, game->player.y);
	ft_free_array(game->map.grid);
	game->map.grid = ft_split(game->tmp_map_grid, '\n');
	if (!game->map.grid)
		exit_error(game, "Memory allocation failed in ft_split.\n");
	//free(game->tmp_map_grid);
}

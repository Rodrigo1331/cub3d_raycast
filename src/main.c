/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:08:01 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/04 17:41:49 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_draw(t_game *game)
{
    int i;

    i = -1;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Couldn't initialize mlx");
    while (++i < 4) //Get the address of the textures
	{
		game->img_text[i].img = mlx_xpm_file_to_image(game->mlx, game->textures[i],
				&game->img_text[i].width, &game->img_text[i].height);
		if (!game->img_text[i].img)
			exit_error(game, "Failed to load texture");
		game->img_text[i].addr = mlx_get_data_addr(game->img_text[i].img, 
			&game->img_text[i].bits_per_pixel, &game->img_text[i].len,
			&game->img_text[i].endian);
		if (!game->img_text[i].addr)
			exit_error(game, "Failed to get texture address");
	}
	game->pixels.width = (int)SCREEN_WIDTH;
	game->pixels.height = (int)SCREEN_HEIGHT;
	game->pixels.img = mlx_new_image(game->mlx, game->pixels.width,
			game->pixels.height);
	if (!game->pixels.img)
		exit_error(game, "New image creation failed");
	game->pixels.addr = mlx_get_data_addr(game->pixels.img,
			&game->pixels.bits_per_pixel, &game->pixels.len, &game->pixels.endian);
	if (!game->pixels.addr)
		exit_error(game, "Image address failed");
	game->win = mlx_new_window(game->mlx, game->pixels.width,
		game->pixels.height, "Cub3D");
	if (!game->win)
		exit_error(game, "New window creation failed!");
}

/*
It checks all in one in the same function:
1. check_args
2. check_file_name
3. check_file_extension
4. check_file_open
5. check_empty_file
*/
void	parse_check_file(int argc, char *file, int i, int fd)
{
	char	*line;

	if (argc != 2 || ft_strlen(file) < 5 || ft_strncmp(file + ft_strlen(file)
			- 4, ".cub", 4) != 0)
		exit_error(NULL, "Invalid arguments, file name, or extension.\n");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, "Failed to open requested file.\n");
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] != '\0' && ft_isspace(line[i]))
			i++;
		if (line[i] != '\0')
		{
			free(line);
			close(fd);
			return ;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	exit_error(NULL, "The file is empty or contains only whitespace.\n");
}

/*
parse_check_file (What it does):
1. check_args, check_file_name, check_file_extension,
check_file_open, check_empty_file: all in one in the same function.

Tokenizer (What it does - separates in tokens,
that are smaller parts of the file):
1. It divides the file into smaller tokens:
	tokens_params (parameters file) and map_grid (map).
2. It takes off spaces at the beginning,
	at the end (such as trim) as also
	at the middle (in between) the tokens_params.
3. Deliver the tokens_params "cleaned" to
	the lexer_assign and the map_grid "cleaned"
	to the map_check_load.

Lexer (What it does - checks/validate the tokens
and decides what to do with them/assigns them):
1. It checks the textures and colors of the
	tokens_params to check if they are valid.
2. It assigns the textures and colors to the game struct.

parse_check_map (What it does - checks the map):
1. It checks the map characters to see if they are valid.
2. It sets the spawn point of the player in the map.
3. It checks the walls of the map using the floodfill
	algorithm to validate if the player is surrounded
	by walls and therefore the map is valid.
*/
void	parser(t_game *game, int ac, char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = 0;
	parse_check_file(ac, file, i, fd);
	tokenizer(game, file);
	lexer(game);
	/* print_game_atributes(game); */
	parse_check_map(game);
}

/*
1 - Initializes the game struct to zero(all elements).
2 - Parses the file looking for the map and the parameters.
3 - Inits mlx and the textures.
4 - Starts the game loop: the raycasting loop and the game loop.
5 - At the end, like in so_long, free is done when
.. we are exiting the game:
... at so_long that happen when we press ESC or X (close window)
... or when we finish the game (collect all collectibles)
... and go to the exit door.
At cub3d that happen only when we press ESC or X (close window).
We don´t have exit door (games keeps running), so we can
.. free everything in exit_esc function.
*/
int	main(int ac, char **av)
{
	t_game	game;

	game = (t_game){0};
	game.ceiling_color = -1;
	game.floor_color = -1;
	parser(&game, ac, av[1]);
	init_draw(&game);
	raycast(&game);
	mlx_hook(game.win, 2, 1L << 0, &key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, &key_release, &game);
	mlx_hook(game.win, 17, 1L << 0, &exit_x, &game);
	mlx_loop_hook(game.mlx, &raycast, &game);
	mlx_loop(game.mlx);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:08:01 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/06 11:15:02 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// game loops - raycasting loop and game loop.
void	cub3d(t_game *game, char *file)
{
	(void)file;
	raycast(game);
	//mlx_hook(game->win, 2, 1L << 0, &key_press, &game);
	//mlx_hook(game->win, 3, 1L << 1, &key_release, &game);
	//mlx_hook(game->win, 17, 1L << 17, exit_esc, &game);
	//mlx_loop_hook(game->mlx, raycast, &game);
	//mlx_loop(game->mlx);
}


//Instead of ft_bzero(game, sizeof(t_game));
//I could also use memset or calloc or just game = (t_game){0};
/* static void	init_game(t_game *game)
{
	setup_game(game);
	setup_mlx(game);
	setup_textures(game);
}
void	setup_mlx_and_textures(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Failed to initialize mlx.\n");
	game->win = mlx_new_window(game->mlx, game->screen_width,
			game->screen_height, "Cub3D");
	if (!game->win)
		exit_error(game, "Failed to create window.\n");
	game->img = mlx_new_image(game->mlx, game->screen_width,
			game->screen_height);
	if (!game->img)
		exit_error(game, "Failed to create image.\n");
	game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
			&game->line_length, &game->endian);
	if (!game->addr)
		exit_error(game, "Failed to get image address.\n");
		
	game->textures[0].img = mlx_xpm_file_to_image(game->mlx, N_XPM,
			&game->textures[0].width, &game->textures[0].height);
	game->textures[1].img = mlx_xpm_file_to_image(game->mlx, S_XPM,
			&game->textures[1].width, &game->textures[1].height);
	game->textures[2].img = mlx_xpm_file_to_image(game->mlx, E_XPM,
			&game->textures[2].width, &game->textures[2].height);
	game->textures[3].img = mlx_xpm_file_to_image(game->mlx, W_XPM,
			&game->textures[3].width, &game->textures[3].height);
			
	if (!game->textures[0].img || !game->textures[1].img
		|| !game->textures[2].img || !game->textures[3].img)
		exit_error(game, "Failed to load textures.\n");
		
	game->textures[0].path = mlx_get_data_addr(game->textures[0].img,
			&game->textures[0].bits_per_pixel, &game->textures[0].line_length,
			&game->textures[0].endian);
	game->textures[1].path = mlx_get_data_addr(game->textures[1].img,
			&game->textures[1].bits_per_pixel, &game->textures[1].line_length,
			&game->textures[1].endian);
	game->textures[2].path = mlx_get_data_addr(game->textures[2].img,
			&game->textures[2].bits_per_pixel, &game->textures[2].line_length,
			&game->textures[2].endian);
	game->textures[3].path = mlx_get_data_addr(game->textures[3].img,
			&game->textures[3].bits_per_pixel, &game->textures[3].line_length,
			&game->textures[3].endian);
			
	if (!game->textures[0].path || !game->textures[1].path
		|| !game->textures[2].path || !game->textures[3].path)
		exit_error(game, "Failed to get textures address.\n");
} */

/* void	print_game_atributes(t_game *game)
{
	printf("Ceiling color: %d\n", game->ceiling_color);
	printf("Floor color: %d\n", game->floor_color);
	printf("NO texture: %s\n", game->textures[0].path);
	printf("SO texture: %s\n", game->textures[1].path);
	printf("WE texture: %s\n", game->textures[2].path);
	printf("EA texture: %s\n", game->textures[3].path);
} */

/* void init_draw(t_game *game)
{
    // Add this part to the "init" folder maybe?
    int i;

    i = -1;
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Couldn't initialize mlx");
    while (++i < 4) //Get the address of the textures
	{
		game->img[i].img = mlx_xpm_file_to_image(game->mlx, game->textures[i].addr,
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
} */

static void	load_textures(t_game *game)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		game->img[i].img = mlx_xpm_file_to_image(game->mlx, game->textures[i],
				&game->img[i].width, &game->img[i].height);
		if (!game->img[i].img)
			exit_error(game, "Failed to load texture");
		game->img[i].addr = mlx_get_data_addr(game->img[i].img,
				&game->img[i].bits_per_pixel, &game->img[i].len,
				&game->img[i].endian);
		if (!game->img[i].addr)
			exit_error(game, "Failed to get texture address");
	}
}

void	init_mlx_and_textures(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_error(game, "Failed to initialize mlx");
	load_textures(game);
	game->screen.width = (int)SCREEN_WIDTH;
	game->screen.height = (int)SCREEN_HEIGHT;
	game->screen.img = mlx_new_image(game->mlx, game->screen.width,
			game->screen.height);
	if (!game->screen.img)
		exit_error(game, "Failed to create new image");
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bits_per_pixel, &game->screen.len, &game->screen.endian);
	if (!game->screen.addr)
		exit_error(game, "Failed to get image address");
	game->win = mlx_new_window(game->mlx, game->screen.width,
			game->screen.height, "Cub3D Bonus");
	if (!game->win)
		exit_error(game, "Failed to create new window");
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
int	main(int argc, char **argv)
{
	t_game	game;

	game = (t_game){0};
	errno = 1;
	game.color[0] = -1;
	game.color[1] = -1;
	if (argc != 2)
		return((exit_error(NULL, "Invalid number of arguments")));
	parse_file(&game, argv[1]);
	//init_draw(&game);
	cub3d (&game, argv[1]);
	return (0);
}

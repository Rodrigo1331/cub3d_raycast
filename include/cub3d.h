/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:17 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/07 10:13:06 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
//# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"

# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
# elif defined(__APPLE__)
#  include "../minilibx_opengl_20191021/mlx.h"
# endif

// ------------ Macros ------------
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64
# define COS 0.99995000041
# define SIN 0.00999983333
# define FOV 0.66

// ------------ Structs ------------

typedef enum e_tile
{
	WALL	= '1',
	FLOOR	= '0',
	NORTH	= 'N',
	SOUTH	= 'S',
	WEST	= 'W',
	EAST	= 'E',
}				t_tile;

// 2d grid struct
typedef struct s_2d_grid
{
	int	x;
	int	y;
}	t_2d_grid;

// Map struct
typedef struct s_map
{
	char		**grid;
	t_2d_grid	checker;
}	t_map;

typedef enum e_key
{
	ESC				= 65307,
	W				= 119,
	A				= 97,
	S				= 115,
	D				= 100,
	P				= 112,
	ROTATE_LEFT		= 65361,
	ROTATE_RIGHT	= 65363,
}	t_key;

// Keys struct
typedef struct s_keys
{
	int	esc;
	int	w;
	int	a;
	int	s;
	int	d;
	int	rotate_left;
	int	rotate_right;
}	t_keys;

// Texture struct
typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		endian;
	int		len;
}	t_texture;

//Draw calculations
typedef struct s_draw
{
	int		start;
	int		end;
	int		line_height;
	double	step;
	double	pos;
}	t_draw;

//Wall calculations
typedef struct s_wall_calc
{
	double	camera_x;
	int		x;
	int		map_x;
	int		map_y;
}	t_wall_calc;

//Ray data
typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	camera_x;
	int		reached_wall;
}	t_ray;

// Player struct
typedef struct s_player
{
	double	x;
	double	y;
	double	new_x;
	double	new_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	float	move_speed;
	float	rot_speed;
}	t_player;

// Main game struct
typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	t_map		map;
	char		*tokens_params[7];
	char		*tmp_map_grid;
	t_player	player;
	t_ray		ray;
	t_draw		draw;
	t_wall_calc	wall_calc;
	t_keys		keys;
	char		*textures[4];
	t_texture	img_text[4];
	t_texture	pixels;
	int			floor_color;
	int			ceiling_color;
}	t_game;

//Parser
void	tokenizer(t_game *game, char *file);
void	lexer(t_game *game);
void	parse_check_map(t_game *game);

//Init
void	setup_game(t_game *game);
void	setup_mlx(t_game *game);
void	setup_textures(t_game *game);

// ------------ Movement ------------
// Key Hooks
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);
void	handle_keys(t_game *game);

//Movement
void	move_forward(t_game *game);
void	move_backward(t_game *game);
void	strafe_left(t_game *game);
void	strafe_right(t_game *game);
void	rotate_left(t_game *game);
void	rotate_right(t_game *game);

int		was_key_pressed(t_game *game);

//Rendering
void	draw(t_game *game, int x);
void	draw_background(t_game *game);
int		raycast(t_game *game);
void	dda_calculations(t_game *game);
void	put_pixil(t_game *game, int x, int y, int color);

//Cleanup - exit/error
void	exit_error(t_game *game, char *msg);
int		exit_game(t_game *game, char *msg);
int		exit_x(t_game *game);
void	free_game(t_game *game);
#endif

/*

cub3d/
├── include/
│   ├── cub3d.h
├── src/
│   ├── main.c
│   ├── parser/
│   │   ├── config.c
│   │   ├── map_loader.c
│   │   └── validation.c
│   ├── init/
│   │   ├── setup_game.c
│   │   ├── setup_mlx.c
│   │   └── setup_textures.c
│   ├── movement/
│   │   ├── player_input.c
│   │   ├── movement_utils.c
│   │   └── rotation.c
│   ├── rendering/
│   │   ├── draw.c
│   │   ├── raycasting.c
│   │   └── textures.c
│   ├── cleanup/
│   │   ├── free_resources.c
│   │   └── exit_game.c
*/

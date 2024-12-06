/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:45:17 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/06 11:27:20 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
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
# define TEXTURE_WIDTH 64 //change this value according to the texture width or use game->texture.width
# define TEXTURE_HEIGHT 64
# define COS 0.99995000041
# define SIN 0.00999983333
# define FOV 0.66
# define VALID_CHARS " 01NSEW\n"
# define SPAWN_CHARS "NSEW"
# define INSIDE_CHARS "0NSEW"
# define DOOR '2'

typedef struct s_game	t_game;

// ------------ Structs ------------

typedef enum e_tile
{
	WALL = '1',
	FLOOR = '0',
	NORTH = 'N',
	SOUTH = 'S',
	WEST = 'W',
    EAST = 'E',
}				t_tile;

// 2d grid struct
typedef struct s_2d_grid
{
    int x;
    int y;
} t_2d_grid;

// Map struct
typedef struct s_map 
{
    char **grid; // Map data: 2D array of characters. Each character represents a different element of the map. 
/*     int rows; // map_height 
    int cols; // map_width */
    t_2d_grid checker; //its used to verify at each deltaStep if its an obstacle.
} t_map;

typedef enum e_key
{
    ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	P = 112,
	ROTATE_LEFT = 65361,
    ROTATE_RIGHT = 65363,
}				t_key;

// Keys struct
typedef struct s_keys
{
    int esc;
    int	w;
	int	a;
	int	s;
	int	d;
    int rotate_left;
    int rotate_right;
} t_keys;

// Texture struct
typedef struct s_img 
{
    void *img; // Image of the texture itself.
    char *addr; //memory address
    int width;
    int height;
    int bits_per_pixel; //HERE!!!!!!!!!!
    int endian;         //HERE!!!!!!!!!!
    int len;            //HERE!!!!!!!!!!
} t_img;

//Draw calculations
typedef struct s_draw
{
    int start;
    int end;
    int line_height;
    double step;
    double pos;
} t_draw;

//Wall calculations
typedef struct s_wall_calc
{
    double camera_x;
    int x;
    int map_x;
    int map_y;
} t_wall_calc;

//Ray data
typedef struct s_ray
{
    //double dir_x; //ray->direction of x
    //double dir_y; //ray->direction of y
    //double side_dist_x; // Distance to the first vertical line the ray hits
    //double side_dist_y; // Distance to the first horizontal line the ray hits
    //double delta_dist_x;// Distance from one vertical line to the next
    //double delta_dist_y;// Distance from one horizontal line to the next
    double perp_wall_dist; //Ray parallel to the player's direction ray
    //int step_x; //1 if positive, -1 if negative
    //int step_y; //1 if positive, -1 if negative
    int hit;    //Position where the ray hit the wall
    int side;   //Which side did the ray hit the wall
    double  camera_x; //[-1, 1] // -1 is the leftmost side of the screen
    int     reached_wall; //if pos += delta as touched a wall
} t_ray;

typedef struct s_vf2d
{
	double	x;
	double	y;
}	t_vf2d;

// Player struct
typedef struct s_player
{
    t_game		*g;
	char		**map;
    t_vf2d		pos;
    t_vf2d      new_pos;
	t_vf2d		dir;
	t_vf2d		ray_dir;
	t_vf2d		plane;
    t_vf2d		side_dist;
    t_vf2d		delta_dist;

    t_2d_grid   step;

    //double x; // Player´s X position
    //double y; // Player´s Y position
    //double new_x; // Player's X position + Step
    //double new_y; // Player's Y position + Step
    //double dir_x; // Player´s direction vector X
    //double dir_y; // Player´s direction vector Y
    //double plane_x; // Player´s camera plane X
    //double plane_y; // Player´s camera plane Y
    float move_speed; // Player´s movement speed
    float rot_speed; // Player´s rotation speed
} t_player;

typedef enum e_texture
{
	we,
	ea,
	no,
	so
}	t_texture;

typedef enum e_color
{
	clg,
	flr
}	t_color;

// Main game struct
typedef struct s_game 
{
    char		*file_line;
    // MLX variables (graphic library)
    void *mlx; // Instance of the mlx library. To allow interaction with the graphic system.
    void *win; // Game window to be rendered. The window where the game will be displayed.
   // void *img; //
    // t_texture screen_image; // Image to be rendered. The image that will be displayed on the window and that´s the background of the game.
    // Game Map (2D representation)
    //t_map map; // The Map of the game: map structure. Contains the map data and its dimensions (width and height).
    char *tokens_params[7]; // Array with the splited map parameters.
    char *tmp_map_grid; // Temporary map grid to store the map data before it´s copied to the map structure.
    
    // Players properties
    //t_player player; // Player´s information: position, direction, etc
    
    // Ray data
    t_ray ray;

    // Draw data
    t_draw draw;
    
    //Wall calculations
    t_wall_calc wall_calc;
    
    // Game controls
    t_keys keys; // Keys controls: up, down, left, right arrows and ESC. 
    
    // Textures
    char *textures[4]; // Texture for the 4 directions for walls and sprites: north, south, east, west, amd the player.
    //t_texture img_text[4];  // void *img inside t_texture struct is the Image to be rendered. The image that will be displayed on the window and that´s the background of the game.
    //t_texture pixels; //HERE!!!!!!!!!!!!!!!!!!!!!!!!!!!
    t_img		img[4];
	t_img		screen;
    // Colors
   // int floor_color;
   // int ceiling_color;

	int			color[2];
	char		**map;
    t_2d_grid   check;
	int			map_height;
	t_player	pl;
} t_game;

//Parser
int	parse_file(t_game *game, char *file);
int	lexer(t_game *game, char **tokens);
void	parse_map(t_game *game, int fd);

//Init
void setup_game(t_game *game);
void setup_mlx(t_game *game);
void setup_textures(t_game *game);

// ------------ Movement ------------
// Key Hooks
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);
void    handle_keys(t_game *game);
//Movement
void move_forward(t_game *game);
void move_backward(t_game *game);
void strafe_left(t_game *game);
void strafe_right(t_game *game);
void rotate_left(t_game *game);
void rotate_right(t_game *game);

int was_key_pressed(t_game *game);

//Rendering
void draw(t_game *game, int x);
void draw_background(t_game *game);
int raycast(t_game *game);
void dda_calculations(t_game *game);
void put_pixil(t_game *game, int x, int y, int color);

//Cleanup - exit/error
int	exit_error(t_game *game, char *message);
int	exit_game(t_game *game, char *msg);
int	exit_esc(t_game *game);
int	free_game(t_game *game);

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:09:53 by antmoren          #+#    #+#             */
/*   Updated: 2023/04/03 13:17:06 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define MAX_LINE_LENGTH 1024

# include "../lib/42-library/includes/ft_printf.h"
# include "../lib/42-library/includes/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_map
{
	int			width;
	int			heigth;
	int			collect_cnt;
	int			player_cnt;
	int			exit_cnt;
	char		**coords;
	char		*path;
	int			exit_posible;
}				t_map;

typedef struct s_img
{
	mlx_image_t	*collectable;
	mlx_image_t	*player_right;
	mlx_image_t	*player_left;
	mlx_image_t	*player_front;
	mlx_image_t	*player_back;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*exit;
}				t_img;

typedef struct s_game
{
	int			player_pos_x;
	int			player_pos_y;
	int			img_size;
	int			score;
	int			steps;
	mlx_t		*mlx;
	t_map		map;
	t_img		img;

}				t_game;

// FUNCTIONS

/* Map */
void			create_map(t_game *game);

/* Textures */
void			load_background(t_game *game);
void			load_player(t_game *game);
void			load_content_map(t_game *game);
void			load_texture_map(int l, t_game *game, int x, int y);
void			delete_img(t_game *game);

/* Check Map */
void			check_map(t_game *game, char *argv);
void			check_counters_map(t_map *map);

/* Check Map Utils*/
void			check_content_map(t_game *game);
void			check_border_map(t_game *game);
void			check_elem_num(t_game *game, t_map *map);
void			check_rectangle_map(t_game *game);
char			*check_path(char *argv);

/* Check Route */
void			check_route(t_game *game);

/* Movement */
void			move_player(mlx_key_data_t keydata, void *param);
void			rotate_player(int n, t_game *game);

/* Utils */
void			print_error(char *message);
void			finish_game(t_game *game);
void			free_map(char **map);

#endif
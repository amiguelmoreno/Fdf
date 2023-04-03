/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:35:16 by antmoren          #+#    #+#             */
/*   Updated: 2023/04/03 12:00:50 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_background(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./assets/img/wall.png");
	game->img.wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/floor.png");
	game->img.floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/collectable.png");
	game->img.collectable = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/exit.png");
	game->img.exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	load_player(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./assets/img/player_right.png");
	game->img.player_right = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/player_left.png");
	game->img.player_left = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/player_front.png");
	game->img.player_front = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./assets/img/player_back.png");
	game->img.player_back = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

void	load_content_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.heigth)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.coords[y][x] == 'C')
				load_texture_map(0, game, x, y);
			if (game->map.coords[y][x] == 'P')
				load_texture_map(1, game, x, y);
			if (game->map.coords[y][x] == 'E')
				load_texture_map(2, game, x, y);
			x++;
		}
		y++;
	}
}

void	load_texture_map(int l, t_game *game, int x, int y)
{
	if (l == 0)
		mlx_image_to_window(game->mlx, game->img.collectable,
			x * game->img_size, y * game->img_size);
	if (l == 1)
	{
		game->player_pos_x = x;
		game->player_pos_y = y;
		mlx_image_to_window(game->mlx, game->img.player_right,
			x * game->img_size, y * game->img_size);
		mlx_image_to_window(game->mlx, game->img.player_left,
			x * game->img_size, y * game->img_size);
		mlx_image_to_window(game->mlx, game->img.player_front,
			x * game->img_size, y * game->img_size);
		mlx_image_to_window(game->mlx, game->img.player_back,
			x * game->img_size, y * game->img_size);
		rotate_player(0, game);
	}
	if (l == 2)
	{
		mlx_image_to_window(game->mlx, game->img.exit,
			x * game->img_size, y * game->img_size);
	}
}

void	delete_img(t_game *game)
{
	mlx_delete_image(game->mlx, game->img.wall);
	mlx_delete_image(game->mlx, game->img.floor);
	mlx_delete_image(game->mlx, game->img.collectable);
	mlx_delete_image(game->mlx, game->img.player_right);
	mlx_delete_image(game->mlx, game->img.player_left);
	mlx_delete_image(game->mlx, game->img.player_front);
	mlx_delete_image(game->mlx, game->img.player_back);
	mlx_delete_image(game->mlx, game->img.exit);
}

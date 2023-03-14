/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:53 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/14 18:29:56 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_player(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->img.player_right, x * game->img_size, y
			* game->img_size);
	mlx_image_to_window(game->mlx, game->img.player_left, x * game->img_size, y
			* game->img_size);
	mlx_image_to_window(game->mlx, game->img.player_front, x * game->img_size, y
			* game->img_size);
	mlx_image_to_window(game->mlx, game->img.player_back, x * game->img_size, y
			* game->img_size);
	rotate_player(0, game);
}

void	display_element(t_game *game, int x, int y)
{
	if (game->map.coords[y][x] == '1')
		mlx_image_to_window(game->mlx, game->img.wall, x * game->img_size, y
				* game->img_size);
	if (ft_strchr("0CEP", game->map.coords[y][x]))
	{
		mlx_image_to_window(game->mlx, game->img.floor, x * game->img_size, y
				* game->img_size);
		if (game->map.coords[y][x] == 'C')
			mlx_image_to_window(game->mlx, game->img.collectable, x
					* game->img_size, y * game->img_size);
		if (game->map.coords[y][x] == 'E')
			mlx_image_to_window(game->mlx, game->img.exit, x * game->img_size, y
					* game->img_size);
		if (game->map.coords[y][x] == 'P')
		{
			display_player(game, x, y);
		}
	}
}

void	create_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	load_background(game);
	load_player(game);
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			display_element(game, x, y);
			x++;
		}
		y++;
	}
	load_content_map(game);
}
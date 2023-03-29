/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:53 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/16 09:57:02 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
			if (game->map.coords[y][x] == '1')
				mlx_image_to_window(game->mlx, game->img.wall, x
						* game->img_size, y * game->img_size);
			if (game->map.coords[y][x] != '1')
				mlx_image_to_window(game->mlx, game->img.floor, x
						* game->img_size, y * game->img_size);
			x++;
		}
		y++;
	}
	load_content_map(game);
}
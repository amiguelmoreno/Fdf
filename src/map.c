/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:38:53 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/29 18:50:35 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	create_map(t_game *game)
{
	int x;
	int y;

	load_background(game);
	load_player(game);
	printf("Es : %d\n", game->map.coords[4][0]);
	printf("alto es: %d\n", game->map.height);
	printf("IMG size es: %d\n", game->img_size);
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (ft_strchr("0CEP", game->map.coords[y][x]))
			{
				mlx_image_to_window(game->mlx, game->img.floor, x * game->img_size, y * game->img_size);
			}
			if (game->map.coords[y][x] == '1')
			{
				mlx_image_to_window(game->mlx, game->img.wall, x * game->img_size, y * game->img_size);
			} 
				printf("X es: %d\n", x);
			x++;
		}
				printf("Y es: %d\n", y);
		y++;
	}
	load_content_map(game);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:17:52 by antmoren          #+#    #+#             */
/*   Updated: 2023/04/03 11:40:38 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_floodfill(t_game *game, int x, int y)
{
	if (x <= 0 || x >= game->map.width || y <= 0 || y >= game->map.heigth
		|| game->map.coords[y][x] == '1' || game->map.coords[y][x] == 'c'
		|| game->map.coords[y][x] == 'o' || game->map.coords[y][x] == 'e'
		|| game->map.coords[y][x] == 'E')
	{
		if (game->map.coords[y][x] == 'E')
			game->map.exit_posible = 1;
		return ;
	}
	if (game->map.coords[y][x] == 'C')
	{
		game->map.collect_cnt--;
		game->map.coords[y][x] = 'c';
	}
	else if (game->map.coords[y][x] == '0')
		game->map.coords[y][x] = 'o';
	ft_floodfill(game, x, (y + 1));
	ft_floodfill(game, x, (y - 1));
	ft_floodfill(game, (x + 1), y);
	ft_floodfill(game, (x - 1), y);
}

void	restore_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.heigth)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.coords[y][x] == 'c')
			{
				game->map.coords[y][x] = 'C';
				game->map.collect_cnt++;
			}
			else if (game->map.coords[y][x] == 'e')
				game->map.coords[y][x] = 'E';
			else if (game->map.coords[y][x] == 'o')
				game->map.coords[y][x] = '0';
			x++;
		}
		y++;
	}
}

void	check_route(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.heigth)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.coords[y][x] == 'P')
			{
				ft_floodfill(game, x, y);
				if (game->map.collect_cnt != 0)
					print_error("The map path must be valid");
				restore_map(game);
				if (game->map.exit_posible == 0)
					print_error("The map path must be valid");
				return ;
			}
			x++;
		}
		y++;
	}
}

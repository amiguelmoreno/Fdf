/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:58:36 by antmoren          #+#    #+#             */
/*   Updated: 2023/04/03 12:52:42 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*check_path(char *argv)
{
	int		file_length;
	char	*aux;

	file_length = ft_strlen(argv);
	aux = ft_substr(argv, file_length - 4, file_length);
	if (ft_strncmp(aux, ".ber", 4) || ft_strncmp(argv, ".ber",
			file_length) == 0)
	{
		print_error("Wrong file format");
	}
	free(aux);
	return (argv);
}

void	check_content_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (game->map.coords[y])
	{
		x = 0;
		while (game->map.coords[y][x])
		{
			if (game->map.coords[y][x] != '0' && game->map.coords[y][x] != '1'
				&& game->map.coords[y][x] != 'E'
				&& game->map.coords[y][x] != 'P'
				&& game->map.coords[y][x] != 'C')
				print_error("Wrong elements in the map");
			x++;
		}
		y++;
	}
}

void	check_elem_num(t_game *game, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.coords[y])
	{
		x = 0;
		while (game->map.coords[y][x])
		{
			if (game->map.coords[y][x] == 'C')
				game->map.collect_cnt++;
			if (game->map.coords[y][x] == 'E')
				game->map.exit_cnt++;
			if (game->map.coords[y][x] == 'P')
			{
				game->map.player_cnt++;
				game->player_pos_x = x;
				game->player_pos_y = y;
			}
			x++;
		}
		y++;
	}
	if (map->player_cnt != 1 || map->exit_cnt != 1 || map->collect_cnt < 1)
		print_error("There are missing or exceding elements");
}

void	check_border_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.coords[y])
	{
		x = 0;
		while (game->map.coords[y][x])
		{
			if (y == 0 && game->map.coords[y][x] != '1')
				print_error("Map is not enclosed by walls");
			if (y == game->map.heigth - 1 && game->map.coords[y][x] != '1')
				print_error("Map is not enclosed by walls");
			if ((x == 0 || x == (game->map.width - 1))
				&& game->map.coords[y][x] != '1')
				print_error("Map is not enclosed by walls");
			x++;
		}
		y++;
	}
}

void	check_rectangle_map(t_game *game)
{
	int	i;
	int	y;

	i = ft_strlen(game->map.coords[0]);
	y = 1;
	while (game->map.coords[y])
	{
		if (i != (int)ft_strlen(game->map.coords[y]))
			print_error("Map is not rectangular");
		y++;
	}
	game->map.heigth = y;
	game->map.width = i;
}

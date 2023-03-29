/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:58:36 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/15 19:15:50 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_content_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->coords[y][x] != 'C' && map->coords[y][x] != 'E'
				&& map->coords[y][x] != 'P' && map->coords[y][x] != '0'
				&& map->coords[y][x] != '1')
				print_error("Wrong elements in the map");
			if (map->coords[y][x] == 'C')
				map->collect_cnt++;
			else if (map->coords[y][x] == 'E')
				map->exit_cnt++;
			else if (map->coords[y][x] == 'P')
				map->player_cnt++;
			x++;
		}
		y++;
	}
	check_counters_map(map);
}

void	check_border_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (y == 0 || y == map->height - 1)
			{
				if (map->coords[y][x] != '1')
					print_error("Map is not enclosed by walls");
			}
			else if ((y > 0 && y < map->height) && (x == 0 || x == map->width
						- 1))
			{
				if (map->coords[y][x] != '1')
					print_error("Map is not enclosed by walls");
			}
			x++;
		}
		y++;
	}
}

void	save_map(t_map *map)
{
	int	fd;
	int	y;

	y = 0;
	map->coords = ft_calloc(map->height, map->width);
	fd = open(map->path, O_RDONLY);
	if (fd == -1)
		print_error("Something went wrong opening the file");
	while (y < map->height)
	{
		map->coords[y] = read_line(fd);
		if (map->width != (int)ft_strlen(map->coords[y]))
			print_error("Map is not rectangular");
		y++;
	}
	close(fd);
}

void	set_width_and_heigth(t_map *map)
{
	int		fd;
	char	*line;

	map->height = 0;
	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		print_error("Something went wrong opening the file");
	line = read_line(fd);
	map->width = ft_strlen(line);
	while (line)
	{
		free(line);
		map->height++;
		line = read_line(fd);
	}
	close(fd);
	free(line);
}

void	check_path(char *argv)
{
	int	file_length;

	file_length = ft_strlen(argv);
	if (ft_strncmp(ft_substr(argv, file_length - 4, file_length), ".ber", 4)
		|| ft_strncmp(argv, ".ber", file_length) == 0)
	{
		print_error("Wrong file format");
	}
}

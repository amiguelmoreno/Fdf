/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:34:25 by antmoren          #+#    #+#             */
/*   Updated: 2023/03/29 20:18:58 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_counters_map(t_map *map)
{
	if (map->collect_cnt < 1 || map->exit_cnt != 1 || map->player_cnt != 1)
	{
		print_error("There are missing or exceding elements");
	}
}

void	check_map(t_map *map, char *argv)
{
	map->collect_cnt = 0;
	map->exit_cnt = 0;
	map->player_cnt = 0;
	map->path = argv;
	check_path(argv);
	set_width_and_heigth(map);
	save_map(map);
	check_border_map(map);
	check_content_map(map);
	check_route(map);
}

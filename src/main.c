/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:35 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/09 21:43:19 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void check_path(char *argv)
{
	 if(ft_strncmp(ft_substr(argv, ft_strlen(argv) - 4, ft_strlen(argv)), ".ber", 4)){
			 printf("Error. Formato incorrecto\n");
			 exit(EXIT_FAILURE);
		 }
		ft_printf("formato correcto\n");
};

void read_map(char *argv, t_map mapa)
{
		(void)mapa;
		check_path(argv);
}

int main(int argc, char **argv)
{
	t_map	mapa;

	if (argc == 2)
	{
			 map_init();
			 read_map(argv[1], mapa);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:35 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/02 11:38:04 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* static mlx_image_t	*img;

void	hook(void *param)
{
	const mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

int32_t	main(void)
{
	mlx_t	*mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
		return (EXIT_FAILURE);
	img = mlx_new_image(mlx, 128, 128);
	memset(img->pixels, 255, img->width * img->height * sizeof(int));
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_image_to_window(mlx, img, 50, 50);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Driver code
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	str = get_next_line(fd);
	ft_printf("%d\n", fd);
	ft_printf("%s\n", str);
	return (0);
}

/* int	main(int argc, char **argv)
{
	FILE	*demo;
	int		display;

	// pointer demo to FILE
	// Creates a file "demo_file"
	// with file access as read mode
	demo = fopen(argv[1], "r");
	// loop to extract every characters
	while (1)
	{
		// reading file
		display = fgetc(demo);
		// end of file indicator
		if (feof(demo))
			break ;
		// displaying every characters
		printf("%c", display);
	}
	// closes the file pointed by demo
	fclose(demo);
	return (0);
} */

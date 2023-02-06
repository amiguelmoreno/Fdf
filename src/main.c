/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:35 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/06 21:14:23 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


# define WIDTH 800
# define HEIGHT 600


 static mlx_image_t	*img;

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



// Driver code
/* 
char	*get_next_line(int fd)
{
	char	*ret = malloc(9999);
	char	c;
	int		i = 0;
	int		cpt = 0;
	if (fd < 0)
		return (NULL);
	while ((cpt = read(fd, &c, 1)) > 0)
	{
		ret[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || cpt < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
}
// Main is here only for testing, do not let him in exam
int		main(int argc, char **argv)
{
	int 	fd = 0;
	char	*line;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line |%s", line);
		free(line);
		line = get_next_line(fd);
	}


	return (0);
} */

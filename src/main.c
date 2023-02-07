/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmoren <antmoren@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:08:35 by antmoren          #+#    #+#             */
/*   Updated: 2023/02/07 21:01:05 by antmoren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* static mlx_image_t *g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
}

void generate_lines(mlx_image_t *g_img)
{
	int i;

	i = 0;

	while(i < 250)
	{
		mlx_put_pixel(g_img, i, i, 0xFFFFFFFF);
		i++;
	}
	i--;
	while(i > 0)
	{
		mlx_put_pixel(g_img, i + 20, i, 0xFFFFFFFF);
		i--;
	}
}

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
    g_img = mlx_new_image(mlx, WIDTH, HEIGHT);    // Creates a new image.
    mlx_image_to_window(mlx, g_img, 0, 0);   // Adds an image to the render queue.
	generate_lines(g_img);
	mlx_loop(mlx);
	mlx_delete_image(mlx, g_img); // Once the application request an exit, cleanup.
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
 */


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
/* 
int get_line_lenght(char *line)
{
	

	return lenght;
} */

// Main is here only for testing, do not let him in exam
int		main(int argc, char **argv)
{
	int 	fd = 0;
	char	*line;
	int 	lenght;
	char 	**elements_array;

	

/* 	if (argc > 1)
		fd = open(argv[1], O_RDONLY); */
	
	line = "jamon:queso:morcilla";
	lenght = 0;
	elements_array = ft_split(line, ':');
	
	ft_printf("%d",	elements_array[0]);

	ft_printf("lenght is %d", lenght);
	/* line = get_next_line(fd);
	while (line != NULL)
	{
		//ft_printf("lenght is %", lenght);
		printf("line |%s", line);
		free(line);
		line = get_next_line(fd);
	}  */
}

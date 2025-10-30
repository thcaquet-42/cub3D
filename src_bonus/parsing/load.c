/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:38:43 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/30 14:46:34 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	load_colors(char *line, int i, t_data *data, int color)
{
	int		*p;
	int		j;

	j = 0;
	p = &data->rgb[color].r;
	i += ft_strcount(&line[i], ' ');
	if (*(p--) == -1 && ft_isdigit((int) line[i]))
	{
		while (++j <= 3 && ++p)
		{
			*p = ft_atoi(&line[i]);
			while (ft_isdigit((int) line[i]))
				++i;
			if (*p >= 0 && *p <= 255
				&& (j == 3 || (ft_isdigit(line[i + 1]) && line[i] == ',')))
				++i;
			else
				clear_exit(1, "(1)" ERROR_RGB, data, line);
		}
	}
	else
		clear_exit(1, "(2)" ERROR_RGB, data, line);
	i += ft_strcount(&line[i - 1], ' ');
	if (line[i - 1] != '\n')
		clear_exit(1, "(3)" ERROR_RGB, data, line);
}

void	load_tex_bis(char *line, char *path, t_data *data, int dir)
{
	int		null;

	data->tex[dir].img = mlx_xpm_file_to_image(\
data->mlx, path, &data->tex[dir].width, &data->tex[dir].height);
	free(path);
	if (data->tex[dir].img == 0)
		clear_exit(1, "(2)"ERROR_LOAD_TEX, data, line);
	data->tex[dir].buf = (uint32_t *)mlx_get_data_addr(\
data->tex[dir].img, &null, &data->tex[dir].size_w, &null);
	if (data->tex[dir].buf == 0)
		clear_exit(1, "(3)"ERROR_LOAD_TEX, data, line);
	data->tex[dir].size_w /= sizeof(data->tex[dir].size_w);
}

void	load_tex(char *line, int len, t_data *data, int dir)
{
	int		i;
	char	*path;

	i = 3;
	while (line[i] == ' ')
		++i;
	path = ft_strndup(&line[i], len - (1 + i));
	if (path == 0)
		clear_exit(1, ERROR_MALLOC, data, line);
	if (data->tex[dir].img == 0)
		load_tex_bis(line, path, data, dir);
	else
		clear_exit(1, ERROR_MULTI_TEX, data, line);
	if (data->tex[dir].img == 0)
		clear_exit(1, "(4)"ERROR_LOAD_TEX, data, line);
}

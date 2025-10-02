/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 20:38:43 by thcaquet          #+#    #+#             */
/*   Updated: 2025/10/02 06:11:20 by thcaquet         ###   ########.fr       */
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
		while (++j <= 3  && ++p)
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

void	load_tex(char *line, int len, t_data *data, int dir)
{
	char	*tmp;
	int		i;
	int		null;

	i = 3;
	while (line[i] == ' ')
		++i;
	if (data->tex[dir].img == 0)
	{
		tmp = ft_strndup(&line[i], len - (1 + i));
		data->tex[dir].img = mlx_xpm_file_to_image(data->mlx, \
			tmp, &data->tex[dir].width, &data->tex[dir].height);
		data->tex[dir].buf =(uint32_t *) mlx_get_data_addr(data->tex[dir].img, &null, \
			&data->tex[dir].size_w, &null);
		data->tex[dir].size_w /= sizeof(data->tex[dir].size_w);
		free(tmp);
	}
	else
		clear_exit(1, ERROR_MULTI_TEX, data, line);
	if (data->tex[dir].img == 0)
		clear_exit(1, ERROR_LOAD_TEX, data, line);
}

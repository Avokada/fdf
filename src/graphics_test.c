#include "../include/fdf.h"

int	ft_ishex(char c)
{
	if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static int	ft_iscolor(char	*str)
{
	int	i;
	int	caps;

	i = 2;
	caps = 0;
	if (!str[0] || !str[7])
		return (0);
	if ((str[0] && str[0] != '0') || !str[1] || (str[1] && str[1] != 'x'))
		return (0);
	while (str[i] && i < 8)
	{
		if (!ft_ishex(str[i]) && !ft_isdigit (str[i]))
			return (0);
		if (str[i] >= 'a' && str[i] <= 'f' && caps == 0)
			caps = -1;
		if (str[i] >= 'A' && str[i] <= 'F' && caps == 0)
			caps = 1;
		if (str[i] >= 'a' && str[i] <= 'f' && caps == 1)
			return (0);
		if (str[i] >= 'A' && str[i] <= 'F' && caps == -1)
			return (0);
		i++;
	}
	return (1);
}

static	int map_type(char *text_map)
{
	int	i;
	int	type;

	i = 0;
	type = 1;
	while (text_map[i])
	{
		if (text_map[i] != ' ' && text_map[i] != ',' && ((!ft_isdigit(text_map[i])\
		&& (text_map[i] == '-' && !ft_isdigit(text_map[i + 1])))))
			return (0);
		else if(text_map[i] == ',')
		{ 
			if (text_map[i + 1] && ft_iscolor(text_map + i + 1))
			{
				i += 7;
				type = 2;
			}
			else
				return (0);
		}
		i++;
	}
	return (type);
}

static int	is_space(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

void	map_free(t_crd **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(*map);
}

static int	num_items(char *str, int type)
{
	int	res;
	int i;

	res = 0;
	i = 1;
	if (type == 1)
	{
		while (str[i] && str[i - 1])
		{
			if (str[i] == ' ' && str[i - 1] >= '0' && str[i - 1] <= '9')
				res++;
			i++;
		}
	}
	else
	{
		while (str[i] && str[i - 1])
		{
			if (str[i] == ' ' && is_space(str[i - 1]))
				res++;
			i++;
		}
	}
	res++;
	return (res);
	
}

static int	len_z(char	*c)
{
	int	i;

	i = 0;
	while (c[i] && c[i] != ' ' && c[i] != '\0' && c[i] != ',')
		i++;
	return (i);	
}

static int	pow_16(int n)
{
	int res;

	res = 1;
	while (n > 0)
	{
		res *= 16;
		n--;
	}
	return (res);
}

static int	ft_hexatoi(char *str)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i ] <= '9')
			res += (((int)str[i] - 48) * pow_16(ft_strlen(str) - i));
		if (str[i] >= 'a' && str[i ] <= 'f')
			res += (((int)str[i] - 87) * pow_16(ft_strlen(str) - i));
		if (str[i] >= 'A' && str[i ] <= 'F')
			res += (((int)str[i] - 55) * pow_16(ft_strlen(str) - i));
		i++;
	}
	return (res);
}

static	void read_colors(char *str, t_fdf *fdf, int j)
{
	int		i;
	char	**txt;
	char	**tmp;

	txt = ft_strsplit(str, ' ');
	if (fdf->col == 0)
	{
		while (txt[fdf->col])
			fdf->col++;
	}
	i = 0;
	if (!(fdf->crd[j] = (t_crd *)malloc(sizeof(t_crd) * (fdf->col + 1))))
		ft_exit(fdf, 0);
	while (txt[i])
	{
		tmp = ft_strsplit(txt[i], ',');
		fdf->crd[j][i].z = ft_atoi(tmp[0]);
		if (!tmp[1])
			fdf->crd[j][i].color = -1;
		else
			fdf->crd[j][i].color = ft_hexatoi(tmp[1] + 2);
		fdf->crd[j][i].x = i;
		fdf->crd[j][i].y = j;
		if (fdf->crd[j][i].z < fdf->low_p)
			fdf->low_p = fdf->crd[j][i].z;
		if (fdf->crd[j][i].z > fdf->top_p)
			fdf->top_p = fdf->crd[j][i].z;
		free_arr(tmp);
		i++;
	}
	free_arr(txt);
}



static	void reading(char *str, t_fdf *fdf, int j)
{
	int 	i;
	char	**txt;

	txt = ft_strsplit(str, ' ');
	if (fdf->col == 0)
	{
		while (txt[fdf->col])
			fdf->col++;
	}
	i = 0;
	if (!(fdf->crd[j] = (t_crd *)malloc(sizeof(t_crd) * (fdf->col + 1))))
		ft_exit(fdf, 0);
	while (txt[i])
	{
		if (i > fdf->col)
			ft_exit(fdf, 3);
		fdf->crd[j][i].color = -1;
		fdf->crd[j][i].x = i;
		fdf->crd[j][i].y = j;
		fdf->crd[j][i].z = ft_atoi(txt[i]);
		if (fdf->crd[j][i].z < fdf->low_p)
			fdf->low_p = fdf->crd[j][i].z;
		if (fdf->crd[j][i].z > fdf->top_p)
			fdf->top_p = fdf->crd[j][i].z;
		i++;
	}
	fdf->crd[j + 1] = NULL;
	if (i < fdf->col)
		ft_exit(fdf, 3);
	free_arr(txt);
}

static	int	make_map(char *argv, t_fdf *fdf)
{
	char	*text_map;
	int		fd;
	int		gnl;
	int		type;
	int		i;

	gnl = 1;
	type = 1;
	i = 0;
	fd = open(argv, O_RDWR);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, &text_map);
		//printf("%s\n", *text_map);
		//printf("292 %i %s\n", gnl, *text_map);
		if (gnl == -1)
		{
			free(text_map);
			return (-1);
		}
		else if (gnl == 1)
		{
			type = map_type(text_map);
			//printf("299 %i\n", type);
			if (!type)
			{
				free(text_map);
				ft_exit(fdf, 3);
			}
			else if (type == 2)
				read_colors(text_map, fdf, i);
			else
				reading(text_map, fdf, i);	
		}
		free(text_map);
		i++;
	}
	if (fdf->row < 2 || fdf->col < 2)
		ft_exit(fdf, 3);
	return (1);
}

static int	count_lines(char *argv)
{
	int		fd;
	int		gnl;
	int		lines;
	char	*text_map;
	
	gnl = 1;
	lines = 0;
	fd = open(argv, O_RDWR);
	while (gnl != 0)
	{
		text_map = NULL;
		gnl = get_next_line(fd, &text_map);
		if (gnl == -1)
		{
			free(text_map);
			return (-1);
		}
		lines++;
		free(text_map);
	}
	close(fd);
	return (lines - 1);
}

t_crd	**val(int argc, char **argv, t_fdf *fdf)
{
	int		fd;
	int		gnl;
	int		makemap;

	if (argc != 2)
		ft_exit(fdf, 2);
	fdf->row = count_lines(argv[1]);
	if (!(fdf->crd = (t_crd **)malloc(sizeof(t_crd *) * (fdf->row + 1))))
		ft_exit(fdf, 0);
	ft_bzero(fdf->crd, fdf->row);
	makemap = make_map(argv[1], fdf);
	//printf("mm: %i\n", makemap);
	if (makemap == -1)
		ft_exit(fdf, 3);
	return (fdf->crd);	
}

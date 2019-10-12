#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef	struct	s_crd
{
	int		z;
	int		x;
	int		y;
	int		color;
	int		full;
}				t_crd;


void	put_nul(t_crd **map)
{
	int i;

	i = 0;	
	while (map[i])
	{
		map[i] = NULL;
		i++;
	}
}


int deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int closed(int key, int i)
{
	if (key == 53)
		exit (0);
	return (0);
}

static	int map_type(char *text_map)
{
	int	i;
	int	type;

	i = 0;
	type = 1;
	while (text_map[i])
	{
		if (!ft_isdigit((int)text_map[i]) && text_map[i] != ' ' && text_map[i] != 'x' && text_map[i] != ',')
			return (0);
		else if(text_map[i - 1] && text_map[i + 1] && text_map[i] == 'x' && (text_map[i - 1] != '0' || !ft_isdigit((int)text_map[i + 1])))
			return (0);
		else if(text_map[i - 1] && text_map[i + 1] && text_map[i] == ',' && (text_map[i + 1] != '0' || !ft_isdigit((int)text_map[i - 1])))
			return (0);
		else if (text_map[i] == 'x' || text_map[i] == ',')
			type = 2;
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
	}
	return (res);
}

static	void read_colors(char *str, t_crd **map)
{
	int i;
	int	j;
	char	**txt;
	char	*tmp;

	j = 0;
	while (map[j] != NULL)
		j++;
	if (!(map[j] = (t_crd *)malloc(sizeof(t_crd) * (num_items(str, 2) + 1))))
	{
		map = NULL;
		return ;
	}
	txt = ft_strsplit(str, ' ');
	i = 0;
	while (txt[i])
	{
		if (!(tmp = (char *)malloc(sizeof(char) * len_z(txt[i]))))
			return ;
		ft_strncpy(tmp, txt[i], len_z(txt[i]));
		map[j][i].z = ft_atoi(tmp);
		free (tmp);
		map[j][i].x = i;
		map[j][i].y = j;
		if (!(tmp = (char *)malloc(sizeof(char) * \
		(ft_strlen(txt[i]) - len_z(txt[i]) - 3))))
			return ;
		ft_strncpy(tmp, &txt[i][len_z(txt[i]) + 2], (ft_strlen(txt[i]) - len_z(txt[i]) - 3));
		map[j][i].color = ft_hexatoi(tmp);
		free(tmp);
		free(txt[i]);
		map[j][i].full = 1;
		i++;
	}
	map[j][i].full = 0;
	free(txt);
}



static	void reading(char *str, t_crd **map)
{
	int 	i;
	int		j;
	char	**txt;

	j = 0;
	while (map[j] != NULL)
		i++;
	if (!(map[j] = (t_crd *)malloc(sizeof(t_crd) * num_items(str, 1))))
	{
		map = NULL;
		return ;
	}
	txt = ft_strsplit(str, ' ');
	i = 0;
	while (txt[i])
	{
		map[j][i].color = -1;
		map[j][i].x = i;
		map[j][i].y = j;
		map[j][i].z = ft_atoi(txt[i]);
		i++;
	}
}

static int	len_row(t_crd *map)
{
	int i;

	i = 0;
	while (map[i].full)
		i++;
	return (i);
}

static int	len_col(t_crd **map, int i)
{
	int j;

	j = 0;
	while (map[j] != NULL && map[j][i].full)
		j++;
	return (j);
}

static int	is_valid(t_crd **map)
{
	int	i;
	int	j;
	int len;

	j = 0;
	len = len_row(map[0]);
	if (!map[1][1].full || !map[0][1].full || !map[1][0].full)
		return (0);
	while (map[j] != NULL)
	{
		if (len != len_row(map[i]))
			return (0);
		j++;
	}
	i = 0;
	len = len_col(map, 0);
	while(map[0][i].full)
	{
		if (len != len_col(map, i))
			return (0);
		i++;
	}
	return (1);
}

static	int	make_map(int argc, char **argv, t_crd **map)
{
	char	**text_map;
	int		fd;
	int		gnl;
	int		type;
	int		tmp;

	gnl = 1;
	type = 1;
	fd = open(argv[1], O_RDWR);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, text_map);
		if (gnl == -1)
			return (-1);
		else if (gnl == 1)
		{
			tmp = type;
			type = map_type(*text_map);
			if (!type)
			{
				map_free(map);
				return (-1);
			}
			else if (type == 2)
				read_colors(*text_map, map);
			else
			{
				reading(*text_map, map);
			}		
		}
	}
	if (is_valid(map))
	{
		map_free(map);
		return (-1);
	}
	return (1);
}

static int	count_lines(char **argv)
{
	int		fd;
	int		gnl;
	int		lines;
	char	**text_map;
	
	gnl = 1;
	lines = 0;
	fd = open(argv[1], O_RDWR);
	while (gnl != 0)
	{
		gnl = get_next_line(fd, text_map);
		if (gnl == -1)
			return (-1);
		lines++;
		//free (*text_map);
	}
	close(fd);
	return (lines);
}

static int	val(int argc, char **argv, t_crd **map)
{
	int		fd;
	int		gnl;
	int		lines;
	int		makemap;

	if (argc < 2)
	{
		map = NULL;
		return (-1);
	}
	lines = count_lines(argv);
	if (!(map = (t_crd **)malloc(sizeof(t_crd *) * lines)))
	{
		map = NULL;
		return (-1);
	}
	put_nul(map);
	makemap = make_map(argc, argv, map);
	if (makemap == -1)
		return (-1);
	return (1);
		
}



int main(int argc, char **argv)
{
	//void *mlx_ptr;
	//void *win_ptr;
	t_crd **point;
	int	i;
	int	j;

	point = NULL;
	
	// mlx_ptr = mlx_init();
	// win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
	if ((val(argc, argv, point)) == (-1))
		exit (0);
	i = 0;
	while (point[i] != NULL)
	{
		j = 0;
		while (point[i][j].full)
		{
			printf("%i ", point[i][j].z);
			j++;
		}
		printf("\n");
	}
	// mlx_key_hook(win_ptr, deal_key, (void *)0);
	// mlx_hook(win_ptr, 2, 0, closed, (void *)0);
	// mlx_loop(mlx_ptr);
}

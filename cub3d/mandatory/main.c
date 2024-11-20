/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbadda <bbadda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:44:58 by bbadda            #+#    #+#             */
/*   Updated: 2024/11/19 17:51:01 by bbadda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_and_fill_map(char *map)
{
	int		fd;
	char	*line;
	char	**str;
	int		i;
	int		j;

	i = 0;
	str = (char **)malloc (10 * sizeof(char *));
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("line %d : %s\n", i, line);
			j = 0;
			while(line[j])
			{
				printf("line[%d] : %c\n",j, line[j]);
				str[i][j] = line[j];
				printf("str[%d][%d]  : %c\n", i, j, str[i][j]);
				j++;
			}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

void	check_valid_map(char *map)
{
	int		fd;
	char	*line;
	int i;
	
	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		// printf("line %d : %s\n", i, line);c
		if (i < 4)
			printf("--> %c%c\n", line[0], line[1]);
		if (i == 5 || i == 6)
			printf("--> %c\n", line[0]);
		if (i > 7)
			printf("line %d  : %s", i, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

int main(int ac, char **av)
{
    if (ac == 2)
	{
		check_file_type(av[1]);
		// check_valid_map(av[1]);
		read_and_fill_map(av[1]);
		
	}
	else
		__error(0, 0);
}
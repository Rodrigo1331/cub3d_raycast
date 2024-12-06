/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:27:11 by luide-so          #+#    #+#             */
/*   Updated: 2024/12/06 11:16:57 by joaosilva        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_open(t_game *game, char *file, char *extension)
{
	int	fd;
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, extension, 4) || len < 5)
		return(exit_error(game, "Invalid file extension"));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return(exit_error(game, "Failed to open file"));
	return (fd);
}

static void	tokenizer(t_game *ga, char **tokens)
{
	int		i;
	int		j;
	int		comma;

	i = 0;
	j = 0;
	comma = 0;
	while (ga->file_line[i] && ft_strchr(" \t\n", ga->file_line[i]))
		i++;
	while (ga->file_line[i])
	{
		tokens[j++] = ga->file_line + i;
		if (j == 1 && ft_isdigit(ga->file_line[i]))
			break ;
		while (ga->file_line[i] && !ft_strchr(" \t\n,", ga->file_line[i]))
			i++;
		comma += (ga->file_line[i] == ',') * (j != 1) * j;
		if (ga->file_line[i])
			ga->file_line[i++] = '\0';
		while (ga->file_line[i] && ft_strchr(" \t\n,", ga->file_line[i]))
			comma += (ga->file_line[i++] == ',') * (j != 1) * j;
		if (j > 4 || (j == 4 && ft_strchr("CF", tokens[0][0]) && comma != 5))
			return(exit_error(ga, "Invalid parameter"), (void)(0));
	}
	tokens[j] = NULL;
}

int	parse_file(t_game *game, char *file)
{
	int		fd;
	char	*tokens[5];
	int		valid_params;

	fd = check_open(game, file, ".cub");
	valid_params = 0;
	while (1)
	{
		game->file_line = get_next_line(fd);
		if (!game->file_line)
			return(exit_error(game, "No map found"));
		tokenizer(game, tokens);
		if (*tokens && ft_isdigit(tokens[0][0]))
			break ;
		if (*tokens)
			valid_params += lexer(game, tokens);
		free(game->file_line);
	}
	if (valid_params != 6)
		return(exit_error(game, "Wrong number of parameters"));
	parse_map(game, fd);
	close(fd);
	return (0);
}

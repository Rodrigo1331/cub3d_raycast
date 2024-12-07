/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcruz-an <rcruz-an@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:56:06 by joaosilva         #+#    #+#             */
/*   Updated: 2024/12/04 17:40:54 by rcruz-an         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

/*
1. It deletes spaces at the beginning of the str.
2. It deletes spaces at the middle (in between) of the str,
but keeps only one space between words (how:
if	(isspace(str[i]) && (j == 0 || isspace(str[j - 1])))
guarantees that. How: if the current character is a space at the
beginning of the str or if the previous character is a space,
it will skip the current character).
3. It deletes spaces at the end of the str.
4. It "closes" the str with '\0'.
*/
char	*trim_spaces(char *str, int i, int j)
{
	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (isspace(str[i]))
		i++;
	while (str[i])
	{
		if (isspace(str[i]))
		{
			if ((j == 1 && (str[0] == 'C' || str[0] == 'F')) || \
				(j >= 2 && (strncmp(&str[j - 2], "NO", 2) == 0 || \
							strncmp(&str[j - 2], "SO", 2) == 0 || \
							strncmp(&str[j - 2], "WE", 2) == 0 || \
							strncmp(&str[j - 2], "EA", 2) == 0)))
				str[j++] = ' ';
			while (isspace(str[i]))
				i++;
		}
		else
			str[j++] = str[i++];
	}
	str[j] = '\0';
	return (str);
}

/*
1. If the map hasn't started and the line is empty, return.
2. If the map hasn't started and the line has a valid character,
the map has started.
3. If the map has started, add the line to the map (map.grid).
4. If the map hasn't started, add the line to the tokens_params.
*/
void	process_line(t_game *game, char *line, int *tokens_index, int i)
{
	char	*trimmed_line;
	char	*old_map_grid;
	int		j;

	trimmed_line = NULL;
	old_map_grid = NULL;
	j = 0;
	if (game->tmp_map_grid)
	{
		old_map_grid = game->tmp_map_grid;
		game->tmp_map_grid = ft_strjoin(old_map_grid, line);
		free(old_map_grid);
		//free(trimmed_line);
		return ;
	}
	trimmed_line = ft_strtrim(line, " ");
	if (!trimmed_line)
		exit_error(game, "Memory allocation failed in ft_strtrim.");
	if (ft_strchr("10", trimmed_line[0]))
		game->tmp_map_grid = ft_strdup(line);
	else if (ft_strchr("NSEWCF", trimmed_line[0]))
		game->tokens_params[(*tokens_index)++] = \
			ft_strdup(trim_spaces(line, i, j));
	free(trimmed_line);
}

/*
Tokenizer (What it does - separates in tokens,
that are smaller parts of the file):
1. It divides the file into smaller tokens:
	tokens_params (parameters file) and map_grid (map).
2. It takes off spaces at the beginning,
	at the end (such as trim) as also
	at the middle (in between) the tokens_params.
3. Deliver the tokens_params "cleaned" to
	the lexer_assign and the map_grid "cleaned"
	to the map_check_load.
4. It checks if the number of parameters is valid.
How?
At function process_line it makes in reality a split_file,
separating the part of the file with the parameters (token_params)
from the part of the file with the map (in this case tmp_map_grid.
And why tmp_map_grid? Because char**grid is a 2D array of characters,
so, and because we need to store the map in a single string
before we can split it (with strjoin. strjoin will join
in a big string all the map. The line of the original file
will will be separated by \n and the end of the string will be
indicated by \0), we store it in a pointer to char and not
in a char**. Then (at parse_check_map) we split that string
(tmp_map_grid) and spilt will return a char** with the map.
Attention: split will erase empty lines, so we need to check
if there is a number (or other char) that will be present
after the map and after the empty lines. And why? Because
if we check it after split (split will erase the empty lines
and join the number after the empty spaces to the map content
itself, generating a valid map...and that´s wrong). To avoid that,
if a number exists after the empty lines that are after the map,
we check it first - before doing the split -in the check_empty_line_in_map
function. If there is a number after the empty lines, we will consider
the map an invalid map).
Tokenizer Flow of the code:
1. Open the file.
2. Read the file line by line.
3. Enter process line, which will separate the file
into tokens_params and tmp_map_grid.
For the map it will be created in the heap - because we
don't know the size of the map. For the tokens_params int
the stack - because we
know the size of the tokens, in this case 6 plus
the NULL terminator. We only copy what is inside the
tokens_params in the heap (with strdup) because we
don´t know the size of the tokens_params line, as also
we need to store it to assign them in the lexer function.
4. In case of an empty line, it will be just ignored
at the process_line function. If the line is empty, it will
be ignored and the program will continue to the next line,
allowing the file to have empty lines between the parameters.
We check the empty lines in the the map only in the parse_check_map
function, namely in the check_empty_line_in_map function.
5. Check number of parameters.
6. If the map hasn't started, exit the program.
*/
void	tokenizer(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		tokens_index;
	int		i;

	tokens_index = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_error(game, "Couldn't open requested file.");
	line = get_next_line(fd);
	while (line && tokens_index < 7)
	{
		process_line(game, line, &tokens_index, i);
		free(line);
		line = get_next_line(fd);
	}
	if (tokens_index != 6)
		exit_error(game, "Invalid number of parameters.\n");
	if (!game->tmp_map_grid)
		exit_error(game, "Map not found.\n");
	game->tokens_params[tokens_index] = NULL;
	close(fd);
}

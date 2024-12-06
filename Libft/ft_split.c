/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-jes <jode-jes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:22:57 by jode-jes          #+#    #+#             */
/*   Updated: 2023/05/08 14:19:38 by jode-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	chr;
	size_t	n_of_words;

	chr = 0;
	n_of_words = 0;
	while (s[chr] && s[chr] == c)
		chr++;
	while (s[chr])
	{
		if (s[chr] != c)
			n_of_words++;
		while ((s[chr] && s[chr] != c))
			chr++;
		while ((s[chr] && s[chr] == c))
			chr++;
	}
	return (n_of_words);
}

size_t	ft_count_letters(char const *s, char c, size_t word)
{
	size_t	n_of_words;
	size_t	chr;
	size_t	n_of_letters;

	n_of_words = 0;
	chr = 0;
	while (s[chr] && s[chr] == c)
		chr++;
	while ((s[chr]) && (word != n_of_words))
	{
		if (s[chr] != c)
			n_of_words++;
		while (s[chr] && s[chr] != c)
			chr++;
		while (s[chr] && s[chr] == c)
			chr++;
	}
	n_of_letters = 0;
	while (s[chr] && s[chr] != c)
	{
		chr++;
		n_of_letters++;
	}
	return (n_of_letters);
}

char	**ft_write_words(char **new_array, size_t n_of_words, const char *s,
		char c)
{
	size_t	word;
	size_t	chr;
	size_t	n_of_letters;

	word = 0;
	chr = 0;
	while (word < n_of_words)
	{
		n_of_letters = 0;
		while (s[chr] && s[chr] == c)
			chr++;
		while (s[chr] && (s[chr] != c))
		{
			new_array[word][n_of_letters] = s[chr];
			chr++;
			n_of_letters++;
		}
		new_array[word][n_of_letters] = '\0';
		word++;
	}
	new_array[n_of_words] = NULL;
	return (new_array);
}

char	**ft_split(char const *s, char c)
{
	char	**new_array;
	size_t	n_of_words;
	size_t	word;

	n_of_words = (ft_count_words(s, c));
	new_array = malloc(sizeof(char *) * (n_of_words + 1));
	if (!new_array)
		return (NULL);
	word = 0;
	while (n_of_words > word)
	{
		new_array[word] = malloc(sizeof(char) * (ft_count_letters(s, c, word)
					+ 1));
		word++;
	}
	return (ft_write_words(new_array, n_of_words, s, c));
}

/* int main()
{
	char str [] = "a fred é fixe";
	char c = ' ';
	char **new_array = ft_split(str, c);
	if (!new_array)
	{
		printf("ft_split returned NULL\n");
		return (1);
	}

	printf("new list:\n");
	int i = 0;
	while (new_array[i] != NULL) {
		printf("%s\n", new_array[i]);
		i++;
	}

	// free memory
   i = 0;
	while (new_array[i] != NULL) {
		free(new_array[i]);
		i++;
	}
	free(new_array);
	return (0);
} */

// char goes through each character (letter or space or other)-->
// in the loop of ft_count_words.
// In ft_split, w goes through each word.-->
// Its a counter that compares the-->
// n_of_words (that returns of ft_n_of_words)-->
// and the w that starts in zero.
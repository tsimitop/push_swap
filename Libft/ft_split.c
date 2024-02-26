/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsimitop <tsimitop@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 13:30:11 by tsimitop          #+#    #+#             */
/*   Updated: 2024/02/26 15:50:42 by tsimitop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*substrings(char const *s, char c, char **array);

static char	**freeing(char **array, int i);

static int	ft_count(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s && s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if ((s[i] != '\0' && s[i] != c))
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

// Allocates (with malloc(3)) and returns an array of strings obtained by
// splitting ’s’ using the character ’c’ as a delimiter. The array must end
// with a NULL pointer.
char	**ft_split(char const *s, char c)
{
	char	**array;

	array = (char **)ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	substrings(s, c, array);
	return (array);
}

static char	*substrings(char const *s, char c, char **array)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	start = 0;
	while (ft_count(s, c) > i)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		array[i] = ft_substr(s, start, (end - start));
		if (!array[i])
			freeing(array, i);
		start = end;
		i++;
	}
	return (array[i]);
}

static char	**freeing(char **array, int i)
{
	while (array[i > 0])
	{
		i--;
		free(array[i - 1]);
	}
	free(array);
	return (NULL);
}

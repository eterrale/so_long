/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeisler <ekeisler@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:36:25 by ekeisler          #+#    #+#             */
/*   Updated: 2024/11/21 14:33:34 by ekeisler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*write_str(char const *s, size_t start, size_t end)
{
	size_t	i;
	char	*rslt;

	rslt = ft_calloc((end - start + 1), sizeof(char));
	if (!rslt)
		return (NULL);
	i = 0;
	while (start < end)
	{
		rslt[i] = s[start];
		start++;
		i++;
	}
	return (rslt);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static void	ft_free(char **rslt, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end)
	{
		if (rslt[i] != NULL)
			free(rslt[i]);
		i++;
	}
	free(rslt);
}

static void	ft_indexwords(size_t *start, size_t *end, char c, const char *s)
{
	while (s[*end] && s[*end] == c)
		*end = *end + 1;
	*start = *end;
	while (s[*end] && s[*end] != c)
		*end = *end + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**rslt;
	size_t	start;
	size_t	end;
	size_t	index_rslt;

	if (!s)
		return (NULL);
	rslt = ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!rslt)
		return (NULL);
	start = 0;
	end = 0;
	index_rslt = 0;
	while (s[end])
	{
		ft_indexwords(&start, &end, c, s);
		if (end > start)
			rslt[index_rslt] = write_str(s, start, end);
		if (end > start && !rslt[index_rslt++])
			return (ft_free(rslt, index_rslt), NULL);
	}
	return (rslt);
}

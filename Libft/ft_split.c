/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:58:47 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/26 20:11:31 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wordlen(char const *s, char c);
static	char	*wordsep(char const *s, char c, int *i);
static	void	ft_free(char **dst);

char	**ft_split(char const *s, char c)
{
	int		w;
	int		i;
	int		j;
	char	**dst;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	w = wordlen(s, c);
	dst = malloc((w + 1) * sizeof(char *));
	if (!dst)
		return (NULL);
	while (j < w)
	{
		dst[j] = wordsep(s, c, &i);
		if (!dst[j])
		{
			ft_free(dst);
			return (NULL);
		}
		j++;
	}
	dst[j] = NULL;
	return (dst);
}

static	int	wordlen(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (s[i] != c && (s[i] >= 32 && s[i] <= 126))
	{
		w++;
		i++;
	}
	while (s[i])
	{
		if ((s[i -1] == c || s[i -1] == '\t')
			&& ((s[i] != c) && (s[i] >= 32 && s[i] <= 126)))
			w++;
		i++;
	}
	return (w);
}

static	char	*wordsep(char const *s, char c, int *i)
{
	char	*dst;
	int		l;

	l = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i] && s[*i] != c)
	{
		if (s[*i] && (s[*i] == '\t' || (s[*i] >= 32 && s[*i] <= 126)))
			l++;
		if (s[*i] != c)
			(*i)++;
	}
	dst = malloc((l + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, &s[*i - l], l + 1);
	while (s[*i] && s[*i] == c)
		(*i)++;
	return (dst);
}

static	void	ft_free(char **dst)
{
	int	i;

	i = 0;
	while (dst[i])
	{
		free(dst[i]);
		i++;
	}
	free (dst);
}

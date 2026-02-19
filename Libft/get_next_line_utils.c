/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:49:10 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/10 18:26:03 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if ((unsigned char) c == '\0')
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

char	*get_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	dest = malloc(get_strlen(s1) * sizeof(const char) + 1);
	if (!dest)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	get_strlen(const char *str)
{
	size_t	total;

	total = 0;
	if (!str)
		return (0);
	while (str[total] != '\0')
		total++;
	return (total);
}

char	*get_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	size_t			i;
	char			*dst;

	i = 0;
	slen = get_strlen(s);
	if (!s)
		return (NULL);
	if (slen <= start || len == 0)
		return (get_strdup(""));
	if (len > slen - start)
		len = slen - start;
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*get_strjoin(char *s1, char *s2)
{
	int		len;
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = get_strlen(s1) + get_strlen(s2);
	dst = malloc (len + 1 * sizeof(char));
	if (!dst)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
	{
		dst[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dst[i] = *s2;
		i++;
		s2++;
	}
	dst[i] = '\0';
	return (dst);
}

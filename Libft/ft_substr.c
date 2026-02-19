/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:09:03 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/03 19:45:19 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	slen;
	size_t			i;
	char			*dst;

	i = 0;
	slen = ft_strlen(s);
	if (slen <= start || len == 0)
		return (ft_strdup(""));
	if (!s)
		return (NULL);
	if (len > slen - start)
		len = slen - start;
	dst = ft_calloc(len + 1, sizeof(char));
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

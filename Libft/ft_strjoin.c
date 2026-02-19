/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:09:24 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/06 18:16:31 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*dst;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
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

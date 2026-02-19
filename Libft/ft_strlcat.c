/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:33:14 by stda-sil          #+#    #+#             */
/*   Updated: 2024/10/30 13:06:40 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	k = 0;
	i = ft_strlen(src);
	j = ft_strlen(dest);
	if (destsize == 0)
		return (i);
	if (destsize <= j)
		return (i + destsize);
	while (src[k] != '\0' && (j + k) < destsize -1)
	{
		dest[j + k] = src[k];
		k++;
	}
	dest[j + k] = '\0';
	return (j + i);
}

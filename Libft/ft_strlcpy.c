/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:18:24 by stda-sil          #+#    #+#             */
/*   Updated: 2024/10/30 13:02:43 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)

{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (size == 0)
		return (j);
	else
	{
		while (src[i] != '\0' && i < (size -1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (j);
	}
}

/*#include <stddef.h>

size_t strlcpy(char *dst, const char *src, size_t dstsize) 
{
    size_t src_len = 0;
    while (src[src_len] != '\0') src_len++;

    if (dstsize > 0) {
        size_t copy_len = (src_len >= dstsize) ? dstsize - 1 : src_len;
        for (size_t i = 0; i < copy_len; i++) {
            dst[i] = src[i];
        }
        dst[copy_len] = '\0';
    }
    return src_len;
}*/

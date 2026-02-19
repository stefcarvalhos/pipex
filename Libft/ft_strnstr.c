/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:25:45 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/01 16:27:08 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] != '\0'
				&& (i + j) < len && haystack[i + j] == needle[j])
			{
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/*#include <stddef.h>  

char *strnstr(const char *haystack, const char *needle, size_t len) 
{
    if (*needle == '\0') return (char *)haystack;

    size_t needle_len = 0;
    while (needle[needle_len] != '\0') 
	{
        needle_len++;
    }
    if (needle_len > len) return NULL;

    for (size_t i = 0; i <= len - needle_len; i++) {
        if (haystack[i] == needle[0] 
			&& strncmp(&haystack[i], needle, needle_len) == 0) {
            return (char *)&haystack[i];
        }
    }

    return NULL;
}*/
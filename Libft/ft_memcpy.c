/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:11:30 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/01 16:22:31 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tempdst;
	const unsigned char	*tempsrc;
	size_t				i;

	tempdst = (unsigned char *) dst;
	tempsrc = (const unsigned char *) src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		tempdst[i] = tempsrc[i];
		i++;
	}
	return (dst);
}

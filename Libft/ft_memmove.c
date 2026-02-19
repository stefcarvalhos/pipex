/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:16:34 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/01 16:22:57 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	unsigned char	*tempdst;
	unsigned char	*tempsrc;
	size_t			k;

	if (!src && !dst)
		return (NULL);
	tempdst = (unsigned char *) dst;
	tempsrc = (unsigned char *) src;
	k = 0;
	if (tempsrc < tempdst)
	{
		while (len-- > 0)
			tempdst[len] = tempsrc[len];
	}
	else
	{
		while (k < len)
		{
			tempdst[k] = tempsrc[k];
			k++;
		}
	}
	return (dst);
}

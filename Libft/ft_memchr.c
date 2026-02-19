/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:36:52 by stda-sil          #+#    #+#             */
/*   Updated: 2024/10/30 13:24:30 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	val;
	size_t			i;

	str = (unsigned char *) s;
	val = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == val)
		{
			return ((void *)&str[i]);
		}
		i++;
	}
	return (NULL);
}

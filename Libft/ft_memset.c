/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:01:18 by stda-sil          #+#    #+#             */
/*   Updated: 2024/10/30 13:07:43 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *) b;
	while (i < len)
	{
		temp[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

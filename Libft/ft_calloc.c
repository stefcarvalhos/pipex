/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:50:47 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/01 16:27:43 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = malloc(num * size);
	i = 0;
	if (!temp)
	{
		return (NULL);
	}
	while (i < size * num)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:51:04 by stda-sil          #+#    #+#             */
/*   Updated: 2024/10/30 13:22:10 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *) &s[i]);
		}
		i++;
	}
	if ((unsigned char) c == '\0')
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}

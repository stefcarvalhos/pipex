/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:08:29 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 15:40:41 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	const char		*box;

	box = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			box = (&s[i]);
		}
		i++;
	}
	if ((unsigned char) c == '\0')
	{
		return ((char *)&s[i]);
	}
	return ((char *) box);
}

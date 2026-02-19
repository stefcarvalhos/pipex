/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:29:57 by stda-sil          #+#    #+#             */
/*   Updated: 2024/11/05 16:19:14 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		f;
	char	*dst;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	f = ft_strlen(s1) -1;
	while (i <= f && ft_strchr(set, s1[i]))
		i++;
	while (f >= i && ft_strchr(set, s1[f]))
		f--;
	dst = malloc((f - i + 2) * sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy (dst, &s1[i], f - i + 2);
	return (dst);
}

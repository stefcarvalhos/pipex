/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:07:50 by stda-sil          #+#    #+#             */
/*   Updated: 2025/04/16 14:18:45 by stda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*aloc;
	char		*dest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	dest = ft_fill_line_buffer(fd, buffer, aloc);
	free (buffer);
	if (!dest)
		return (aloc = NULL, NULL);
	aloc = ft_set_line(dest);
	return (dest);
}

char	*ft_fill_line_buffer(int fd, char *buffer, char *aloc)
{
	ssize_t	i;
	char	*temp;

	i = 1;
	while (i != 0)
	{
		i = read (fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free(aloc), NULL);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!aloc)
			aloc = get_strdup("");
		if (!aloc)
			return (NULL);
		temp = aloc;
		aloc = get_strjoin(temp, buffer);
		free (temp);
		if (!aloc)
			return (NULL);
		if (get_strchr(aloc, '\n'))
			break ;
	}
	return (aloc);
}

char	*ft_set_line(char *dest)
{
	int		i;
	char	*rest;

	i = 0;
	while (dest[i] != '\0' && dest[i] != '\n')
		i++;
	if (dest[i] == '\0')
		return (NULL);
	rest = get_substr(dest, i + 1, get_strlen(dest) - i);
	if (!rest)
		return (NULL);
	if (*rest == '\0')
	{
		free(rest);
		rest = NULL;
	}
	dest[i + 1] = '\0';
	return (rest);
}

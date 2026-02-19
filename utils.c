/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:34:26 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 10:34:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int is_perror)
{
	if (is_perror == 1)
		perror(msg);
	else
		ft_printf("%s\n", msg);
	exit(1);
}

void	ft_strfree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_cleanexit(char *cmd, char *path, int exit_code)
{
	if (cmd)
		free(cmd);
	if (path)
		free(path);
	exit(exit_code);
}

void	ft_closeexit(int *fd, int exit_code)
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
	if (exit_code >= 0)
		exit(exit_code);
}

void	ft_exit_free(char **cmd, char *path, int *fd, int exit_code)
{
	if (cmd)
		ft_strfree(cmd);
	if (path)
		free(path);
	ft_closeexit(fd, exit_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 23:14:27 by marvin            #+#    #+#             */
/*   Updated: 2025/04/25 23:14:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_checkpath(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) && *(envp[i] + 5))
			return ;
		i++;
	}
	ft_error ("Error! PATH not found in environment", 0);
}

char	**ft_list_dirs(char **envp)
{
	char	**lst_dirs;
	int		i;

	i = 0;
	ft_checkpath(envp);
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	lst_dirs = ft_split(envp[i] + 5, ':');
	if (!lst_dirs)
		ft_error("Error! Failed to split PATH", 0);
	return (lst_dirs);
}

char	*ft_find_fullcmd(char **lst_dirs, char *cmd)
{
	char	*full_cmd;
	char	*tmp;
	int		i;

	i = 0;
	while (lst_dirs[i])
	{
		tmp = ft_strjoin(lst_dirs[i], "/");
		if (!tmp)
			ft_error("Error memory allocation", 0);
		full_cmd = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!full_cmd)
			ft_error("Error memory allocation", 0);
		if (access(full_cmd, F_OK | X_OK) == 0)
			return (full_cmd);
		free(full_cmd);
		i++;
	}
	return (NULL);
}

char	*ft_getpath(char *cmd, char **envp, char **cmd_all)
{
	char	**lst_dirs;
	char	*path;

	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	lst_dirs = ft_list_dirs(envp);
	if (!lst_dirs)
		ft_error("Error! Failed to parse PATH", 0);
	path = ft_find_fullcmd(lst_dirs, cmd);
	ft_strfree(lst_dirs);
	if (!path)
	{
		ft_putstr_fd("Error! Command not found\n", 2);
		free(cmd_all);
		ft_cleanexit(cmd, path, 127);
	}
	return (path);
}

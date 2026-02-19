/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 10:20:35 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 10:20:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <sys/wait.h>
# include "Libft/libft.h"

void	ft_error(char *msg, int is_perror);
void	ft_strfree(char **str);
void	ft_cleanexit(char *cmd, char *path, int exit_code);
void	ft_closeexit(int *fd, int exit_code);
void	ft_exit_free(char **cmd, char *path, int *fd, int exit_code);
void	ft_checkpath(char **envp);
char	**ft_list_dirs(char **envp);
char	*ft_find_fullcmd(char **lst_dirs, char *cmd);
char	*ft_getpath(char *cmd, char **envp, char **cmd_all);
void	ft_exec_cmd(char **envp, char *args, int *fd);
void	ft_child_one(int *fd, char **envp, char **av);
void	ft_child_two(int *fd, char **envp, char **av);
int		ft_waitchild(pid_t	pid1, int *fd);
int		main(int ac, char **av, char **envp);

#endif
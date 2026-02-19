/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:42:26 by marvin            #+#    #+#             */
/*   Updated: 2025/04/24 09:42:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec_cmd(char **envp, char *args, int *fd)
{
	char	**cmd;
	char	*path;

	if (!args || !args[0])
	{
		ft_putstr_fd("Error! Command not found\n", 2);
		ft_closeexit(fd, 127);
	}
	cmd = ft_split(args, ' ');
	if (!cmd)
	{
		close(fd[0]);
		close(fd[1]);
		ft_error("Error memory allocation", 0);
	}
	path = ft_getpath(cmd[0], envp, cmd);
	if (!path)
	{
		ft_exit_free(cmd, NULL, fd, 127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		perror("execve");
		ft_exit_free(cmd, path, fd, 126);
	}
}

void	ft_child_one(int *fd, char **envp, char **av)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		ft_error("Error opening infile", 1);
	if (dup2(infile, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("dup2 error", 1);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	ft_exec_cmd(envp, av[2], fd);
}

void	ft_child_two(int *fd, char **envp, char **av)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error("Error opening outfile", 1);
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
		ft_error("dup2 error", 1);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	ft_exec_cmd(envp, av[3], fd);
}

int	ft_waitchild(pid_t	pid1, int *fd)
{
	int	status;
	int	exitstatus;

	exitstatus = 0;
	waitpid(pid1, &status, 0);
	if (WIFEXITED(status))
	{
		exitstatus = WEXITSTATUS(status);
		if (exitstatus == 127 || exitstatus == 126)
		{
			close(fd[0]);
			close(fd[1]);
			exit(exitstatus);
		}
	}
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (ac != 5)
		ft_error("Error! Invalid quantity of arguments", 0);
	if (pipe(fd) == -1)
		ft_error("Error creating pipe", 1);
	pid1 = fork();
	if (pid1 == -1)
		ft_error("Error creating child one", 1);
	if (pid1 == 0)
		ft_child_one(fd, envp, av);
	pid2 = fork();
	if (pid2 == -1)
		ft_error("Error creating child two", 1);
	if (pid2 == 0)
		ft_child_two(fd, envp, av);
	ft_closeexit(fd, -1);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

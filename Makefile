# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 10:17:40 by marvin            #+#    #+#              #
#    Updated: 2025/04/26 17:05:27 by stda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFTDIR = Libft
RM = rm -rf
SRCS = utils.c \
path.c \
pipex.c \

OBJS = $(SRCS:.c=.o)

INCLUDE = -L ./Libft -lft

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	@make -s -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) ${INCLUDE}

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make -s -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	@make -s -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re


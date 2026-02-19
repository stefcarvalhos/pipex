# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stda-sil <stda-sil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 14:48:19 by stda-sil          #+#    #+#              #
#    Updated: 2025/04/10 17:40:08 by stda-sil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
SRCS = ft_isalpha.c \
ft_memcpy.c \
ft_strlcpy.c \
ft_toupper.c \
ft_isascii.c \
ft_memmove.c \
ft_strlen.c \
ft_atoi.c \
ft_isdigit.c \
ft_memset.c \
ft_strncmp.c \
ft_strcmp.c \
ft_bzero.c \
ft_isprint.c \
ft_strchr.c \
ft_strnstr.c \
ft_calloc.c \
ft_memchr.c \
ft_strdup.c \
ft_strrchr.c \
ft_isalnum.c \
ft_memcmp.c \
ft_strlcat.c \
ft_tolower.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_substr.c \
ft_strtrim.c \
ft_strjoin.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_split.c \
ft_lstnew_bonus.c \
ft_lstadd_front_bonus.c \
ft_lstsize_bonus.c \
ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c \
ft_lstdelone_bonus.c \
ft_lstclear_bonus.c \
ft_lstiter_bonus.c \
ft_lstmap_bonus.c \
ft_printf.c \
ft_print_c.c \
ft_print_di.c \
ft_print_p.c \
ft_print_s.c \
ft_print_u.c \
ft_print_x.c \
get_next_line.c \
get_next_line_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 17:09:58 by ccroissa          #+#    #+#              #
#    Updated: 2020/02/19 17:10:01 by ccroissa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_memcmp.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcpy.c \
		  ft_memset.c \
		  ft_memmove.c \
		  ft_strlcpy.c \
		  ft_strncmp.c \
		  ft_strlen.c \
		  ft_tolower.c \
		  ft_toupper.c \
		  ft_strrchr.c \
		  ft_strnstr.c \
		  ft_strdup.c \
		  ft_calloc.c \
		  ft_strlcat.c \
		  ft_substr.c \
		  ft_strtrim.c \
		  ft_cmpchar.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_split.c \
		  ft_strchr.c \
		  ft_strjoin.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  itoa_base.c \
		  uitoa.c \
		  ft_putstr.c \
		  ft_strcat.c \
		  ft_strncat_mod.c \
		  ft_strcat_mod.c \
		  ft_realloc_mod.c \
		  uitoa_base.c

HEADER	= libft.h

OBJS    = ${SRCS:.c=.o}

BNS		= ${SRCS:.c=.o}

NAME    = libft.a

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

RM      = rm -f

$(NAME):	${OBJS} ${HEADER} 
			${CC} ${CFLAGS} -c ${SRCS}
			ar rc ${NAME} ${OBJS}

bonus:		${OBJS} ${HEADER}
			${CC} ${CFLAGS} -c ${SRCS}
			ar rc ${NAME} ${OBJS}

all:        ${NAME}

clean:
	${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:         fclean all

.PHONY:     all clean fclean re

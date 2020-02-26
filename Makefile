# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccroissa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 16:22:59 by ccroissa          #+#    #+#              #
#    Updated: 2020/02/24 16:37:50 by ccroissa         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCS	= conversions.c \
		  ft_printf.c \
		  ft_printf_parsing.c \
		  ft_printf_utils.c \
		  ft_printf_utils2.c \
		  ft_printf_output.c

LIBFT	= libft/

LIBFT_MAKE = make -C libft/

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -rf

$(NAME):	$(OBJS)
			$(LIBFT_MAKE)
			cp libft/libft.a ./$(NAME)
			ar rc $(NAME) $(OBJS) $(LIB)

all:		$(NAME)

%.o: %.c ft_printf.h libft/libft.h
		$(CC) -I includes/ -o $@ -c $< $(CFLAGS)

clean:
	${RM} ${OBJS}
	make clean -C libft/

fclean:		clean
			$(RM) $(NAME)
			make fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean fclean re





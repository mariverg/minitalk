# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mariverg <mariverg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/29 13:44:36 by mariverg          #+#    #+#              #
#    Updated: 2024/05/23 15:06:39 by mariverg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRCS 	= 	ft_printf.c\
			ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c\
			ft_prinft_hex_tolower.c\
			ft_putptr.c\
			ft_putnbr_unsigned.c\
			ft_prinft_hex_toupper.c\


CC		= 	gcc
FLAGS 	= 	-Wall -Werror -Wextra
INCLUDE =   ft_printf.h

OBJS 	= 	${SRCS:.c=.o}

all: ${NAME}


${NAME}: ${OBJS}
	@ar rcs $(NAME) $(OBJS) 

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f ${OBJS} 

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re 
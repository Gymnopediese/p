# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: albaud <albaud@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/18 13:07:44 by albaud            #+#    #+#              #
#    Updated: 2023/02/14 20:13:51 by albaud           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS 	= p.c srcs/ft_putarrma_fd.c srcs/ft_putbool_fd.c srcs/ft_putchar_fd.c srcs/ft_putdouble_fd.c srcs/ft_putfd_fd.c srcs/ft_putfile_fd.c srcs/ft_putia_clean.c srcs/ft_putintm.c srcs/ft_putlst_fd.c srcs/ft_putnbr_fd.c srcs/ft_putpointer_fd.c srcs/ft_putstr_fd.c srcs/ft_putstra_clean.c srcs/ft_putstruct_fd.c srcs/ft_struct_utils.c progressbar.c
OBJS 	= ${SRCS:.c=.o}
NAME 	= p.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o 	:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
		
all 	: $(NAME)

$(NAME)	: ${OBJS}
		ar rcs ${NAME} ${OBJS}

clean	:
		rm -f ${OBJS} p

fclean	:	clean
		rm -f ${NAME} p

re		: fclean all

test	: ${NAME} p
		./p
p		:
		${CC} ${CFLAGS} ${NAME} main.c -o p


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgilles <rgilles@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 20:58:21 by rgilles           #+#    #+#              #
#    Updated: 2021/04/13 20:58:22 by rgilles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C	=	checker
NAME_PS	=	push_swap

CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror -g

INCL	=	includes/
LIBFT_D	=	Libft/

SRCSD_C	=	srcs/chkr/
SRCSF_C	=	main.c apply_sort.c
SRCS_C	=	$(addprefix ${SRCSD_C},${SRCSF_C})
OBJS_C	=	${SRCS_C:.c=.o}

SRCSD_PS=	srcs/ps/
SRCSF_PS=	main.c maths_tools.c sort_simple.c sort_many.c sort_many_aux.c
SRCS_PS	=	$(addprefix ${SRCSD_PS},${SRCSF_PS})
OBJS_PS	=	${SRCS_PS:.c=.o}

SRCSD_CO=	srcs/common/
SRCSF_CO=	swap.c push.c rotate.c rrotate.c utils.c error_handling.c
SRCS_CO	=	$(addprefix ${SRCSD_CO},${SRCSF_CO})
OBJS_CO	=	${SRCS_CO:.c=.o}




.c.o	:		${INCL}checker.h ${INCL}push_swap.h ${LIBFT_D}${INCL}libft.h
			${CC} ${CFLAGS} -I${LIBFT_D}${INCL} -I${INCL} -c $< -o ${<:.c=.o}

all	:		${NAME_PS}

full :		all ${NAME_C}

${NAME_C}	:	${OBJS_C} ${OBJS_CO}
			make -C ${LIBFT_D}
			${CC} ${CFLAGS} -o ${NAME_C} ${OBJS_C} ${OBJS_CO} ${LIBFT_D}libft.a

${NAME_PS}	:	${OBJS_PS} ${OBJS_CO}
			make -C ${LIBFT_D}
			${CC} ${CFLAGS} -o ${NAME_PS} ${OBJS_PS} ${OBJS_CO} ${LIBFT_D}libft.a
clean	:
			find . -type f -name "*.o" -delete

fclean	:	clean
			find . -type f -name "*.a" -delete
			rm -rf ${NAME_C} ${NAME_PS}

re	:		fclean all

.PHONY	:	re clean fclean

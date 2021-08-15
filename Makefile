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
LIBFT	=	Libft/

SRCSD_C	=	srcs/checker/
SRCSF_C	=	main.c apply_sort.c
SRCS_C	=	$(addprefix ${SRCSD_C},${SRCSF_C})
OBJS_C	=	${SRCS_C:.c=.o}

SRCSD_PS=	srcs/push_swap/
SRCSF_PS=	main.c maths_tools.c sort_simple.c sort_many.c sort_many_aux.c
SRCS_PS	=	$(addprefix ${SRCSD_PS},${SRCSF_PS})
OBJS_PS	=	${SRCS_PS:.c=.o}

SRCSD_CO=	srcs/common/
SRCSF_CO=	swap.c push.c rotate.c rrotate.c utils.c
SRCS_CO	=	$(addprefix ${SRCSD_CO},${SRCSF_CO})
OBJS_CO	=	${SRCS_CO:.c=.o}




.c.o	:		${INCL}checker.h ${INCL}push_swap.h ${LIBFT}${INCL}libft.h
			${CC} ${CFLAGS} -I${LIBFT}${INCL} -I${INCL} -c $< -o ${<:.c=.o}

all	:		${NAME_PS}

full :		all ${NAME_C}

${NAME_C}	:	_libft ${OBJS_C} ${OBJS_CO}
			${CC} ${CFLAGS} -o ${NAME_C} ${OBJS_C} ${OBJS_CO} ${LIBFT}libft.a

${NAME_PS}	:	_libft ${OBJS_PS} ${OBJS_CO}
			${CC} ${CFLAGS} -o ${NAME_PS} ${OBJS_PS} ${OBJS_CO} ${LIBFT}libft.a
clean	:
			find . -type f -name "*.o" -delete

fclean	:	clean
			find . -type f -name "*.a" -delete
			rm -rf ${NAME_C} ${NAME_PS}

re	:		fclean all

_libft	:
			make -C ${LIBFT}

.PHONY	:	re clean fclean

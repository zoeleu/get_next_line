NAME		= get_next_line

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3 -c

INCDIR		= .

SRCS		= get_next_line.c get_next_line_utils.c test.c
OBJS		= ${SRCS:.c=.o}

BONUS_SRCS	= get_next_line_bonus.c get_next_line_utils_bonus.c test_bonus.c get_next_line_bonus.h
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}

RM		= rm -f

all:		${NAME}

bonus:		${BONUS_OBJS}
			gcc -o ${NAME}_bonus {BONUS_OBJS}

%.o: %.c
			${CC} ${CFLAGS} $< -o $@ -I ${INCDIR}

${NAME}:	${OBJS}
			gcc -no-pie -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re: 		fclean all

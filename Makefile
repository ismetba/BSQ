SRCS = $(wildcard srcs/*.c)

OBJS = ${SRCS:.c=.o}

INCS = ./includes

NAME = bsq

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MAPS = map*

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

mclean:
	${RM} ${MAPS}

fclean: clean mclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re mclean
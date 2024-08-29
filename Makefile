SRCS = ./srcs/main.c \
		./srcs/error.c \
		./srcs/file_ops.c

OBJS = ${SRCS:.c=.o}

INCS = ./includes

NAME = bsq

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I {INCS}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
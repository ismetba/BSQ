SRCS = ${wildcard srcs/*.c}

OBJS = ${SRCS:.c=.o}

INCS = ./includes

BIN_DIR = ./bin

NAME = bsq

EXE = ${BIN_DIR}/${NAME}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MAPS = map*

$(shell mkdir -p bin)

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

${EXE}: ${OBJS}
	${CC} ${CFLAGS} -o ${EXE} ${OBJS}

all: $${EXE}

clean:
	${RM} ${OBJS}

mclean:
	${RM} ${MAPS}

fclean: clean mclean
	${RM} ${BIN_DIR}

bin:
	mkdir -p bin

re: fclean all

.PHONY: all clean fclean re mclean
SRCS = ${wildcard srcs/*.c}

SRCS += ${wildcard srcs/commons/*.c}

OBJS = ${SRCS:.c=.o}

INCS = ./includes

BIN_DIR = ./bin

NAME = bsq

EXE = ${BIN_DIR}/${NAME}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

MAPS = map*

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

${EXE}: ${OBJS}
	$(shell mkdir -p bin)
	${CC} ${CFLAGS} -o ${EXE} ${OBJS}

all: ${EXE}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${BIN_DIR}

bin:
	mkdir -p bin

re: fclean all

.PHONY: all clean fclean re bin
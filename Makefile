CC = cc

SRC = main.c
OBJ = ${SRC:.c=.o}

LIBS = -lbsd
CFLAGS = -std=c99 -Wall -pedantic -Wextra -Os
LDFLAGS = ${LIBS}

all: passwdgen

debug: CFLAGS += -O0 -g
debug: passwdgen

.c.o:
	${CC} -c ${CFLAGS} $<

passwdgen: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f passwdgen ${OBJ}

.PHONY: all clean debug

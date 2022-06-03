CC = cc

SRC = main.c
OBJ = ${SRC:.c=.o}

LIBS = -lbsd
CFLAGS = -std=c99 -Wall -pedantic -Wextra -Os
LDFLAGS = ${LIBS}

# Install paths
PREFIX = /usr/local
MANPREFIX = ${PREFIX}/share/man

all: passwdgen

debug: CFLAGS += -O0 -g
debug: passwdgen

.c.o:
	${CC} -c ${CFLAGS} $<

passwdgen: ${OBJ}
	${CC} -o $@ ${OBJ} ${LDFLAGS}

clean:
	rm -f passwdgen ${OBJ}

install: all
	mkdir -p ${PREFIX}/bin
	cp -f passwdgen ${PREFIX}/bin
	chmod 755 ${PREFIX}/bin/passwdgen
	mkdir -p ${MANPREFIX}/man1
	cp -f passwdgen.1 ${MANPREFIX}/man1
	chmod 644 ${MANPREFIX}/man1/passwdgen.1

uninstall:
	rm -f ${PREFIX}/bin/passwdgen\
		${PREFIX}/man1/passwdgen.1

.PHONY: all clean debug install uninstall

CC?=gcc
CFLAGS=-Wall -Wextra -Wshadow -std=c11 -pedantic -ggdb
LIBS=-lraylib
SRC=src/main.c

layout: $(SRC)
	$(CC) $(CFLAGS) -o layout $(SRC) $(LIBS)
clean:
	rm layout

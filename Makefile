CC?=gcc
CFLAGS=-Wall -Wextra -std=c11 -ggdb
LIBS=-lraylib -lm -ldl -lpthread
SRC=src/main.c

layout: $(SRC)
	$(CC) $(CFLAGS) -o layout $(SRC) $(LIBS)
clean:
	rm layout

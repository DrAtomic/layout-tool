CC?=gcc
CFLAGS=-Wall -Wextra -std=c11 -ggdb 
LIBS=-lraylib -lm -lpthread -ldl
SRC=src/main.c

layout: $(SRC)
	$(CC) $(CFLAGS) -o layout $(SRC) $(LIBS)
clean:
	rm layout

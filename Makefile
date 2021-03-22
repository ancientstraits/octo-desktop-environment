CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`
SRC = *.c
EXEC = main
CC = gcc


$(EXEC): $(SRC) *.h
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LIBS)

CC = gcc
PROJECT = octo
GTK_FLAGS := `pkg-config --cflags gtk+-3.0`
GTK_LIBS :=  `pkg-config --libs gtk+-3.0`
INCDIR = include
SRC := src
CFLAGS := $(GTK_FLAGS) -I$(INCDIR)
LIBS := $(GTK_LIBS)
OBJ := obj

SOURCES := $(wildcard $(SRC)/*.c)
OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))

all: $(OBJECTS)
	bear -- $(CC) $(CFLAGS) $^ -o $(PROJECT) $(LIBS)

$(OBJ)/%.o: $(SRC)/%.c $(wildcard$(INCDIR)/*.h)
	$(CC) $(CFLAGS) -c $< -o $@

clean: all
	rm -rf obj/*.o


install: all $(PROJECT) ui/octo.xml
	install -m 755 octo /usr/local/bin
	[ -d /usr/local/share/octo ] && \
	install -m 755 ui/octo.xml /usr/local/share/octo/octo.xml || \
	mkdir /usr/local/share/octo && \
	install -m 755 ui/octo.xml /usr/local/share/octo/octo.xml

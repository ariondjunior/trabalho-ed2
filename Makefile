CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.
TARGET = app

SRCS = \
	index.c \
	menu/cadastro.c \
	menu/contato.c \
	menu/relatorios.c \
	TAD/fila/fila.c \
	TAD/listadc/listadc.c \
	utilities/utilities.c


OBJS = $(SRCS:.c=.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

# Definisci il nome del programma finale
TARGET = simple-enc

# Definisci i percorsi delle directory
SRCDIR = src
INCDIR = include
BINDIR = bin

# Definisci i file sorgente
SRCS = $(wildcard $(SRCDIR)/*.c)

# Definisci i file oggetto
OBJS = $(patsubst $(SRCDIR)/%.c, $(BINDIR)/%.o, $(SRCS))

# Definisci i flag del compilatore
CC = gcc
CFLAGS = -g -Wall -I$(INCDIR)

# Regola predefinita
all: $(BINDIR)/$(TARGET)

# Compila i file oggetto
$(BINDIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compila i file sorgente in file oggetto
$(BINDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Pulisci i file intermedi e l'eseguibile
clean:
	rm -f $(BINDIR)/$(TARGET) $(OBJS)


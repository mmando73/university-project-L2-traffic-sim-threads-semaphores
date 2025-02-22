CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lpthread
BINDIR=./bin
SRCDIR=./src
INCLUDEDIR=./include
DOCDIR=./doc
TESTDIR=./tests
OBJDIR=$(BINDIR)/obj
TARGET=$(BINDIR)/gestionTrafic

# Liste de tous les fichiers .c à compiler
SOURCES=$(wildcard $(SRCDIR)/*.c)
# Convertir la liste des sources en liste d'objets
OBJECTS=$(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# En-têtes
HEADERS=$(wildcard $(INCLUDEDIR)/*.h)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJDIR)/*

# Commandes pour générer la documentation, tester, etc.
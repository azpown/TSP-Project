PREFIX=.
LIBDIR = $(PREFIX)/lib
CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
LDFLAGS = -L../lib -lmatrice
DIRS = ArbrePlanaire Arete Graphe Input NearestNeighbour Prim-MST Tas


all:
	for i in $(DIRS) ; do make -C $$i ; done


libmatrice.a : $(OBJ)
	for i in $(DIRS) ; do make -C $$i ; done
	ar -cr libmatrice.a $(OBJ)

install:
	mv libmatrice.a $(PREFIX)../lib
#	cp input.h $(PREFIX)/bin
#	cp manipgraph.h $(PREFIX)/graphic


.PHONY: clean
clean :
	for i in $(DIRS) ; do make clean -C $$i ; done
#	rm -f $(LIBDIR)/$(LIB);

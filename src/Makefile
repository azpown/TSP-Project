PREFIX=.
LIBDIR = $(PREFIX)/lib
CC = gcc
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
FIND_FILES = $(wildcard $(dir)/*)
DIRS := ArbrePlanaire Arete Graphe Input NearestNeighbour Prim-MST Tas
FILES := $(foreach dir,$(DIRS),$(FIND_FILES))



Voyager:$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o Voyager


all:
	for $(FILES) in $(DIRS) ; do make -C $$i ;
	done


#libmatrice.a :manipgraph.o input.o
#	for i in */ ; do make -C $$i ; done
#	ar -cr matrice.a input.o manipgraph.o

#install:
#	mv libmatrice.a $(PREFIX)/lib
#	cp input.h $(PREFIX)/bin
#	cp manipgraph.h $(PREFIX)/graphic


.PHONY: clean
clean :
	rm -f $(OBJ) $(OUTFILE);
#	rm -f $(LIBDIR)/$(LIB);

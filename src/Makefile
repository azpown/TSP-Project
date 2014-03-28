LIBNAME = bibli
LIBRARY = lib$(LIBNAME).a
LIBDIR = ../lib
CC = gcc
DIRS = ArbrePlanaire Arete Graphe Input NearestNeighbour Prim-MST Tas
OBJS = $(foreach dir,$(DIRS),$(wildcard $(dir)/*.o))

all: $(LIBRARY)
#	for i in $(DIRS) ; do make -C $$i ; done

objets:
	for i in $(DIRS) ; do \
		$(MAKE) -C $$i ; \
	done

$(LIBRARY): objets
	for i in $(DIRS) ; do \
		ar -rs $@ $(OBJS) ; \
	done

.PHONY: clean install
clean :
	for i in $(DIRS) ; do make clean -C $$i ; done
	rm -f $(LIBRARY) *~
install:
	mv libbibli.a $(LIBDIR)

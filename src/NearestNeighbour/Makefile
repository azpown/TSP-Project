CC = gcc
EXEC = testNearestNeighbour
CFLAGS = -std=c99 -O2
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : ${EXEC}

${EXEC} : depend $(OBJ)
	${CC} -o $@ ${OBJ}

.PHONY : clean
clean :
	rm edit $(OBJ)
depend : 
	$(CC) -MM $(SRC) > depends.txt


testt : testManipGraph.o manipGraph.o
	gcc testManipGraph.o manipGraph.o -o testt

manipGraph.o : manipGraph.c manipGraph.h
	gcc -std=c99 -c manipGraph.c

testManipGraph.o : testManipGraph.c manipGraph.h
	gcc -std=c99 -c testManipGraph.c

.PHONY : clean runTest
clean :
	rm *Graph.o 
runTest :
	./testt




